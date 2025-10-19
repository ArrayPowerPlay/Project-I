// Given a undirected graph =(V,E) in which V = {1,2,..,n} is the set of nodes
// Write a program that visit nodes of G by a DFS 
// (consider a lexicorgraphic order of nodes)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    // n: number of nodes
    // m: number of edges
    cin >> n >> m;
    vector<vector<int>> adjacent(n + 1);
    vector<int> visited(n + 1, 0);

    int x, y;

    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }

    for(int i = 1; i <= n; ++i) {
        sort(adjacent[i].begin(), adjacent[i].end());
    }

    stack<int> st;
    st.push(1);

    while(!st.empty()) {
        int u = st.top();
        st.pop();

        if(!visited[u]) {
            visited[u] = 1;
            cout << u << " ";

            for(int i = adjacent[u].size() - 1; i >= 0; --i) {
                int t = adjacent[u][i];

                if(!visited[t]) {
                    st.push(t);
                }
            }
        }
    }


}