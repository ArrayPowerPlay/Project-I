// Given a directed graph G = (V,E) in which V = {1,2,...,n) is the set of nodes
// Each arc (u,v) has a non-negative weight w(u,v)
// Given two nodes s and t of G. Find the shortest path from s to t on G.

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;

int min_path(int n, int src, int des, vector<vector<pair<int, int>>> &adj) {
    vector<int> dist(n + 1, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if(d > dist[u]) continue;
        else {
            if(u == des) return dist[u];
            for(auto [v, w] : adj[u]) {
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    return -1;
}

int main() {
    // nodes and edges
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    int x, y, w;
    for(int i = 1; i <= m; ++i) {
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }

    int s, t;
    cin >> s >> t;

    cout << min_path(n, s, t, adj) << endl;
}