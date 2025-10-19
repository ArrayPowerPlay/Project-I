// Given positive integers k and m. 
// Compute the number Q of k-subsequences such that the weight is even.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    int sum = 0;
    // number of even k-subsequences
    int res = 0;
    cin >> n >> k;
    vector<int> a(n);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(int i = 0; i <= n - k; ++i) {
        if(i == 0) {
            for(int j = 0; j < k; ++j) {
                sum += a[j];
            }
        } else {
            sum = sum - a[i - 1] + a[i + k - 1];
        }
        if (sum % 2 == 0) res++;
    }

    cout << res << endl;
}