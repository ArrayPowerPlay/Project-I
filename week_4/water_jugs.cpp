// There are two jugs, a-litres jug and b-litres jug (a, b are positive integers)
// There is a pump with unlimited water. Given a positive integer c
// how to get exactly c litres.
// write the number of steps or write -1 (if no solution found)
// code using BFS

#include <bits/stdc++.h>
using namespace std;

struct state {
    // x, y is the current litres of water in the two jugs
    int x, y, step;
    state(int _x, int _y, int _step): x(_x), y(_y), step(_step) {}
};

int gcd(int a, int b) {
    while(a != b) {
        if(a > b) a = a - b;
        else b = b - a;
    }
    return a;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(c > max(a, b) || c % gcd(a, b) != 0) {
        cout << -1 << endl;
        return 0;
    }

    queue<state> q;
    set<pair<int, int>> visited;
    q.push(state(0, 0, 0));
    visited.insert({0, 0});

    while(!q.empty()) {
        auto [x, y, step] = q.front();
        q.pop();

        if(x == c || y == c) {
            cout << step << endl;
            return 0;
        }

        vector<pair<int, int>> nextStates = {
            {0, y}, 
            {x, 0},
            {a, y}, 
            {x, b},
            {x - min(x, b - y), y + min(x, b - y)}, 
            {x + min(y, a - x), y - min(y, a - x)}
        };

        for(auto [xx, yy] : nextStates) {
            if(visited.find({xx, yy}) == visited.end()) {
                visited.insert({xx, yy});
                q.push(state(xx, yy, step + 1));
            }
        }
    }

}