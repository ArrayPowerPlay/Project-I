// Given undirected graph G = (V,E) in which V = {1, 2, ..., n} is the set of nodes
// and E is the set of m edges.
// Write a program that computes the sequence of nodes visited using a BFS algorithm 
// (the nodes are considered in a lexicographic order)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    int n, m;
    // n: number of nodes
    // m: number of edges
    cin >> n >> m;
    vector<vector<int>> adjacent(n + 1);
    vector<int> visited(n + 1, 0);

    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }

    // sort each adjacent vector so that our BFS algorithm will visit nodes
    // in lexicographic order
    for(int i = 1; i <= n; ++i) {
        sort(adjacent[i].begin(), adjacent[i].end());
    }

    // BFS traversal for all connected components
    for(int start = 1; start <= n; ++start) {
        if(!visited[start]) {
            queue<int> q;
            q.push(start);
            visited[start] = 1;

            while(!q.empty()) {
                int node = q.front();
                q.pop();
                cout << node << " ";

                for(auto p : adjacent[node]) {
                    if(!visited[p]) {
                        visited[p] = 1;
                        q.push(p);
                    }
                }
            }
        }
    }
}