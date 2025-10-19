// Given an undirected graph G = (V,E)
// Write a program to check if G is a Hamiltonian graph

#include <bits/stdc++.h>
using namespace std;

// n: number of nodes
// m: number of edges
int n, m;
vector<vector<int>> adjacent;
vector<int> visited;
vector<int> track_node;
// final result
// 0: no hamilton cycle
// 1: exist hamilton cycle
bool res = false;
// count number of nodes have been tranversed

// start: starting node
void backtrack(int index, int start) {
    if(res == true) return;

    for(int t : adjacent[track_node[index - 1]]) {
        if(!visited[t]) {
            visited[t] = 1;
            track_node[index] = t;

            if(index == n) {
                for(int t : adjacent[track_node[index]]) {
                    if(t == start) {
                        res = true;
                        return;
                    }
                }
            } else {
                backtrack(index + 1, start);
            }

            // backtrack
            visited[t] = 0;
        }
    }
}

int main() {
    int x, y;
    int t;
    cin >> t;
    
    for(int k = 0; k < t; ++k) {
        res = false;

        cin >> n >> m;

        if(n == 1) {
            cout << 1 << endl;
            return 0;
        }

        adjacent.resize(n + 1);
        visited.assign(n + 1, 0);
        track_node.resize(n + 1);

        visited[1] = 1;
        track_node[1] = 1;

        for(int i = 0; i < m; ++i) {
            cin >> x >> y;
            adjacent[x].push_back(y);
            adjacent[y].push_back(x);
        }

        for(int i = 1; i <= n; ++i) {
            sort(adjacent[i].begin(), adjacent[i].end());
        }

        backtrack(2, 1);
        cout << res << endl;
    }
}
