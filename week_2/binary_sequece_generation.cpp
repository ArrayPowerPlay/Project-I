// Given an integer n, write a program that generates all the binary sequences 
// of length n in a lexicographic order.

#include <bits/stdc++.h>
using namespace std;

void try_binary(int k, int n, vector<int>& arr) {
    for(int v = 0; v <= 1; ++v) {
        if (k > 1 && arr[k - 1] == 1 && v == 1) continue;

        arr[k] = v;
        if(k == n) {
            for(int i = 1; i <= n; ++i) cout << arr[i];
            cout << endl;
        } else {
            try_binary(k + 1, n, arr);
        }
    }
}

int main() {
    int n; 
    cin >> n;
    vector<int> arr(n + 1);

    try_binary(1, n, arr);
}