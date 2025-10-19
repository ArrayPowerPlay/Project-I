#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    unordered_set<int> st;

    for(int i = 0; i < n; ++i) {
        cin >> x;
        if(st.find(x) != st.end()) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        st.insert(x);
    }
    
}