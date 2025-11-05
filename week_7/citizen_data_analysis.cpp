#include <bits/stdc++.h>
using namespace std;

struct Person {
    string father, mother;
    string status;
    string dob;
    vector<string> children;
};

unordered_map<string, Person> ppl;
unordered_map<string, array<int, 2>> dp;
unordered_set<string> visited_dfs;

vector<string> forests;
unordered_set<string> processed;

// find max unrelated people of a tree with root 's'
int dfs(string s) {
    // if(visited_dfs.count(s)) {
    //     return max(dp[s][0], dp[s][1]);
    // }

    if(dp.find(s) != dp.end()) {
        return max(dp[s][0], dp[s][1]);
    }

    // visited_dfs.insert(s);
    // max unrelated people of a tree if we don't choose 's'
    dp[s][0] = 0;
    // max unrelated people of a tree if we choose 's'
    dp[s][1] = 1;
    
    for(string &child : ppl[s].children) {
        if(dp.find(child) == dp.end()) {
            dfs(child);
        }

        dp[s][0] += max(dp[child][0], dp[child][1]);
        dp[s][1] += dp[child][0];
    }
    return max(dp[s][0], dp[s][1]);
}

int maxAncestor(const string &s, unordered_set<string> &visited) {
    // return the distance between the oldest ancestor that is alive and s
    // return 0 if cannot find
    if(visited.find(s) != visited.end()) return 0;
    visited.insert(s);
    int maxDist = 0;

    for(string ancester : {ppl[s].father, ppl[s].mother}) {
        if(ancester == "0000000") continue;
        if(ppl.find(ancester) == ppl.end()) continue;
        
        if(ppl[ancester].status == "Y") {
            maxDist = 1;
        }

        int dist = maxAncestor(ancester, visited);

        if(dist != 0) {
            maxDist = max(maxDist, 1 + dist);
        }
    }

    return maxDist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int num_ppl = 0;
    unordered_map<string, int> num_ppl_born_at;
    // <personID, <ancesterID, ancesterStatus> 
    unordered_map<string, bool> visited;
    vector<string> date;
    vector<string> person_list;

    cin >> s;

    while(s != "*") {
        string dob, father_code, mother_code, status, region_code;
        cin >> dob >> father_code >> mother_code >> status >> region_code;

        ++num_ppl;
        ++num_ppl_born_at[dob];
        date.push_back(dob);

        Person &p = ppl[s];
        p.father = father_code;
        p.mother = mother_code;
        p.status = status;
        p.dob = dob;
        
        person_list.push_back(s);

        cin >> s;
    }

    cin >> s;
    sort(date.begin(), date.end());

    // "0000000" is the virtual root node, which is the ancester of all other nodes
    // Therefore, we calculate max unrelated people by not taking "0000000" into account
    // vector<string> roots;

    // for (auto &person : ppl) {
    //     const string &id = person.first;
    //     const Person &pp = person.second;

    //     if (pp.father == "0000000" && pp.mother == "0000000") {
    //         roots.push_back(id);
    //     }
    // }

    // visited_dfs.clear();
    // dp.clear();
    // int max_unrelated = 0;
    // for (auto &root : roots) {
    //     max_unrelated += dfs(root);
    // }

    // Xây dựng quan hệ cha-con sau khi đã đọc hết input
    unordered_map<string, bool> has_parent;

    for (const string &id : person_list) has_parent[id] = false;

    for (const string &id : person_list) {
        const Person &p = ppl[id];
        if (p.father != "0000000" && ppl.find(p.father) != ppl.end()) {
            ppl[p.father].children.push_back(id);
            has_parent[id] = true;
        }
        if (p.mother != "0000000" && ppl.find(p.mother) != ppl.end()) {
            ppl[p.mother].children.push_back(id);
            has_parent[id] = true;
        }
    }

    // Collect roots: people who do not have any parent inside the DB
    vector<string> roots;
    for (const string &id : person_list) {
        if (!has_parent[id]) roots.push_back(id);
    }

    dp.clear();
    int max_unrelated = 0;
    
    for (const string &root : roots) {
        max_unrelated += dfs(root);
    }

    while(s != "***") {
        if(s == "NUMBER_PEOPLE") {
            cout << num_ppl << endl;
        } else if(s == "NUMBER_PEOPLE_BORN_AT") {
            string dob;
            cin >> dob;

            cout << num_ppl_born_at[dob] << endl;
        } else if(s == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string d1, d2;
            cin >> d1 >> d2;

            auto L = lower_bound(date.begin(), date.end(), d1);
            auto R = upper_bound(date.begin(), date.end(), d2);
            
            cout << (R - L) << endl;
        } else if(s == "MOST_ALIVE_ANCESTOR") {
            string personID;
            cin >> personID;

            unordered_set<string> visited;
            
            if(ppl.find(personID) == ppl.end()) cout << 0 << endl;
            else {
                unordered_set<string> visited;
                cout << maxAncestor(personID, visited) << endl;
            }
        } else {
            cout << max_unrelated << endl;
        }

        cin >> s;
    }
}