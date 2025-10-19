// Write te value C(k,n) modulo 10^9+7.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

vector<vector<int>> res(1000, vector<int>(1000, -1));

ull Ckn(int k, int n) {
    ull mod = 1e9 + 7;
    if(res[k][n] != -1) return res[k][n] % mod;

    if(k == n) {
        res[k][n] = 1;
    } else if(k == 1) {
        res[k][n] = n;
    } else {
        res[k][n] = Ckn(k - 1, n - 1) + Ckn(k, n - 1);
    }
    return res[k][n] % mod;
}

int main() {
    int n, k;
    cin >> k >> n;
    cout << Ckn(k, n) << endl;
}