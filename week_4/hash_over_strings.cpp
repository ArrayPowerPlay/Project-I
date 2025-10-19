#include <bits/stdc++.h>
using namespace std;

int hash_over_str(const string &s, const int &m) {
    int res = 0;
    int k = s.size();
    
    for(char c : s) {
        res = (res * 256 + c) % m;
    }

    return res % m;
}

int main() {
    int n, m;
    cin >> n >> m;
    string s;

    for(int i = 0; i < n; ++i) {
        cin >> s;
        cout << hash_over_str(s, m) << endl;
    }
}