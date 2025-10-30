// Given a directed graph G = (V, E) in which V = {1, 2, ..., n} is the set of nodes
// and w(u,v) is the weight (length) of the arc(u,v)
// Compute d(u,v) - the length of the shortest path from u to v in G, for all u,v in V.


#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;

void dijkstra(int n, int source, vector<vector<pair<int, int>>> &adj) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        // old unoptimized path 
        if(d > dist[u]) continue;
        for(auto [v, w] : adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 1; i <= n; ++i) cout << dist[i] << " ";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // number of nodes and edges
    int n, m;    
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);

    int x, y, w;
    for(int i = 1; i <= m; ++i) {
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }

    for(int src = 1; src <= n; ++src) {
        dijkstra(n, src, adj);
        cout << endl;
    }
}