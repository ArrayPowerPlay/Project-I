// Given a undirected connected graph G=(V,E) where V={1,…,N}
// Each edge (u,v) ∈ E(u,v) ∈ E has weight w(u,v)
// Compute minimum spanning tree of G

#include <bits/stdc++.h>
using namespace std;

// use Prim algorithm
int main() {
    // n: number of nodes
    // m: number of edges
    int n, m;
    int res = 0;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> visited(n + 1, 0);
    
    int x, y, z;
    for(int i = 0; i < m; ++i) {
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    // pq store elements of type {min_weight_to_spanning_tree, node} 
    pq.push({0, 1});

    while(!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if(visited[u]) continue;
        visited[u] = 1;
        res += w;

        for(auto [adj_node, weight] : adj[u]) {
            if(!visited[adj_node]) {
                pq.push({weight, adj_node});
            }
        }
    }

    cout << res << endl;
}
