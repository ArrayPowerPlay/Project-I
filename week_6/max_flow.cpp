// Given a network G = (V, E) which is a directed weighted graph
// Node s is the source and node t is the target. c(u,v) is the capacity of the arc (u,v)
// Find the maximum flow on G

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v;            // đỉnh tới
    int capacity;     // trọng số của cạnh
    int rev;          // chỉ số của cạnh ngược trong adj[v]
};

int n, m;
const int INF = 1e8;
vector<vector<Edge>> adj;

// add an edge into graph
void addEdge(int u, int v, int cap) {
    Edge a = {v, cap, adj[v].size()};
    Edge b = {u, 0 , adj[u].size()};
    adj[u].push_back(a);
    adj[v].push_back(b);
}

// check if we can find a augmenting path from s to t in graph
bool checkBFS(int src, int des, vector<int> &parent, vector<int> &edge_index) {
    fill(parent.begin(), parent.end(), -1);
    parent[src] = src;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(u == des) return true;

        for(int i = 0; i < adj[u].size(); ++i) {
            Edge &e = adj[u][i];

            if(parent[e.v] == -1 && e.capacity > 0) {
                parent[e.v] = u;
                edge_index[e.v] = i;
                q.push(e.v);
            }
        }
    }

    return false;
}

// apply Edmonds Karp algorithm
int Edmonds_Karp(int src, int des) {
    int max_flow = 0;
    // parent[u] = previous node of node u in founded path
    vector<int> parent(n + 1);
    // edge_index[u] = i and parent[u] = v means adj[v][i] = u
    vector<int> edge_index(n + 1);
    
    while(checkBFS(src, des, parent, edge_index)) {
        int flow_path = INF;

        for(int v = des; v != src; v = parent[v]) {
            int u = parent[v];
            int idx = edge_index[v];
            int cap = adj[u][idx].capacity;
            flow_path = min(flow_path, cap);
        }

        // update weights of edges
        for(int v = des; v != src; v = parent[v]) {
            int u = parent[v];
            int idx = edge_index[v];
            Edge &e = adj[u][idx];
            e.capacity -= flow_path;
            adj[v][e.rev].capacity += flow_path;
        }

        max_flow += flow_path;
    }

    return max_flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // nodes and edges
    cin >> n >> m;
    int s, t;
    cin >> s >> t;

    adj.resize(n + 1);

    int x, y, w;
    for(int i = 1; i <= m; ++i) {
        cin >> x >> y >> w;
        addEdge(x, y, w);
    }

    cout << Edmonds_Karp(s, t) << endl;
}
