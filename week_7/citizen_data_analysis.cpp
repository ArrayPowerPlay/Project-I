#include <bits/stdc++.h>
using namespace std;

struct Person {
    string father;
    string mother;
    bool alive;
    string dob;
};

struct HopcroftKarp {
    int nLeft;
    int nRight;
    vector<vector<int>> adj;
    vector<int> dist;
    vector<int> matchLeft;
    vector<int> matchRight;

    HopcroftKarp(int nl, int nr, vector<vector<int>> g)
        : nLeft(nl),
          nRight(nr),
          adj(std::move(g)),
          dist(nl, -1),
          matchLeft(nl, -1),
          matchRight(nr, -1) {}

    bool bfs() {
        queue<int> q;
        fill(dist.begin(), dist.end(), -1);
        for (int u = 0; u < nLeft; ++u) {
            if (matchLeft[u] == -1) {
                dist[u] = 0;
                q.push(u);
            }
        }

        bool reachedFreeRight = false;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                int matchedU = matchRight[v];
                if (matchedU == -1) {
                    reachedFreeRight = true;
                } else if (dist[matchedU] == -1) {
                    dist[matchedU] = dist[u] + 1;
                    q.push(matchedU);
                }
            }
        }
        return reachedFreeRight;
    }

    bool dfs(int u) {
        for (int v : adj[u]) {
            int matchedU = matchRight[v];
            if (matchedU == -1 ||
                (dist[matchedU] == dist[u] + 1 && dfs(matchedU))) {
                matchLeft[u] = v;
                matchRight[v] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    }

    int maxMatching() {
        if (nLeft == 0 || nRight == 0) {
            return 0;
        }

        int matching = 0;
        while (bfs()) {
            for (int u = 0; u < nLeft; ++u) {
                if (matchLeft[u] == -1 && dfs(u)) {
                    ++matching;
                }
            }
        }
        return matching;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, int> idOf;
    vector<Person> people;
    vector<string> codes;
    unordered_map<string, int> bornAtCount;
    vector<string> dobList;

    string code;
    if (!(cin >> code)) {
        return 0;
    }

    while (code != "*") {
        string dob, father, mother, status, region;
        cin >> dob >> father >> mother >> status >> region;

        Person person{father, mother, status == "Y", dob};
        idOf[code] = static_cast<int>(people.size());
        people.push_back(person);
        codes.push_back(code);
        ++bornAtCount[dob];
        dobList.push_back(dob);

        if (!(cin >> code)) {
            break;
        }
    }

    const int n = static_cast<int>(people.size());
    vector<string> sortedDob = dobList;
    sort(sortedDob.begin(), sortedDob.end());

    vector<array<int, 2>> parents(n, array<int, 2>{-1, -1});
    vector<vector<int>> graph(n);

    for (int i = 0; i < n; ++i) {
        array<string, 2> parentCodes{people[i].father, people[i].mother};
        for (int j = 0; j < 2; ++j) {
            const string &pcode = parentCodes[j];
            if (pcode == "0000000") {
                continue;
            }
            auto it = idOf.find(pcode);
            if (it == idOf.end()) {
                continue;
            }
            int pid = it->second;
            parents[i][j] = pid;
            graph[i].push_back(pid);
            graph[pid].push_back(i);
        }
    }

    vector<int> ancestorMemo(n, -1);
    vector<uint8_t> ancestorState(n, 0);

    function<int(int)> farthestAliveAncestor = [&](int u) -> int {
        if (u < 0) {
            return 0;
        }
        if (ancestorState[u] == 2) {
            return ancestorMemo[u];
        }
        if (ancestorState[u] == 1) {
            return 0;
        }

        ancestorState[u] = 1;
        int best = 0;
        for (int parent : parents[u]) {
            if (parent == -1) {
                continue;
            }
            int candidate = 0;
            if (people[parent].alive) {
                candidate = 1;
            }
            int further = farthestAliveAncestor(parent);
            if (further > 0) {
                candidate = max(candidate, 1 + further);
            }
            best = max(best, candidate);
        }
        ancestorState[u] = 2;
        ancestorMemo[u] = best;
        return best;
    };

    vector<int> color(n, -1);
    bool bipartite = true;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (color[i] != -1) {
            continue;
        }
        color[i] = 0;
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                } else if (color[v] == color[u]) {
                    bipartite = false;
                }
            }
        }
    }

    int maxUnrelated = 0;
    if (bipartite) {
        vector<int> leftIndex(n, -1);
        vector<int> rightIndex(n, -1);
        int leftCount = 0;
        int rightCount = 0;
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                leftIndex[i] = leftCount++;
            } else {
                rightIndex[i] = rightCount++;
            }
        }

        vector<vector<int>> hkAdj(leftCount);
        for (int i = 0; i < n; ++i) {
            if (color[i] != 0) {
                continue;
            }
            int u = leftIndex[i];
            for (int v : graph[i]) {
                if (color[v] == 1) {
                    hkAdj[u].push_back(rightIndex[v]);
                }
            }
        }

        HopcroftKarp hk(leftCount, rightCount, std::move(hkAdj));
        int matching = hk.maxMatching();
        maxUnrelated = n - matching;
    } else {
        // Should not happen for valid genealogy, but guard with simple fallback.
        vector<bool> used(n, false);
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return graph[a].size() < graph[b].size();
        });
        for (int u : order) {
            if (used[u]) {
                continue;
            }
            bool ok = true;
            for (int v : graph[u]) {
                if (used[v]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                used[u] = true;
                ++maxUnrelated;
            }
        }
    }

    string query;
    while (cin >> query && query != "***") {
        if (query == "NUMBER_PEOPLE") {
            cout << n << '\n';
        } else if (query == "NUMBER_PEOPLE_BORN_AT") {
            string dob;
            cin >> dob;
            auto it = bornAtCount.find(dob);
            cout << (it == bornAtCount.end() ? 0 : it->second) << '\n';
        } else if (query == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string fromDate, toDate;
            cin >> fromDate >> toDate;
            auto leftIt = lower_bound(sortedDob.begin(), sortedDob.end(), fromDate);
            auto rightIt =
                upper_bound(sortedDob.begin(), sortedDob.end(), toDate);
            cout << static_cast<int>(rightIt - leftIt) << '\n';
        } else if (query == "MOST_ALIVE_ANCESTOR") {
            string target;
            cin >> target;
            auto it = idOf.find(target);
            if (it == idOf.end()) {
                cout << 0 << '\n';
            } else {
                cout << farthestAliveAncestor(it->second) << '\n';
            }
        } else if (query == "MAX_UNRELATED_PEOPLE") {
            cout << maxUnrelated << '\n';
        }
    }

    return 0;
}

