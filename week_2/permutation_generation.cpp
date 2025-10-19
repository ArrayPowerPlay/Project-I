// Given an integer n, write a program to generate all permutations of 
// 1, 2, ..., n in a lexicalgraphic order 
// (elements of a permutation are separated by a SPACE character)

#include <bits/stdc++.h>
using namespace std;
    
void permutation(int k, int n, vector<int>& arr, vector<int>& check) {
    for(int v = 1; v <= n; ++v) {
        if(check[v] == 0) {
            check[v] = 1;
            arr[k] = v;
            if(k == n) {
                for(int i = 1; i <= n; ++i) cout << arr[i] << " ";
                cout << endl;
            } else {
                permutation(k + 1, n, arr, check);
            }
            // backtrack
            check[v] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> check = vector<int>(n + 1, 0);
    vector<int> arr(n + 1);
    permutation(1, n, arr, check);
}