// count the number of pairs of number in a vector that the sum 
// of it equal to a number
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> a(n);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int left = 0, right = n - 1;

    while(left < right) {
        if(a[left] + a[right] < m) {
            left++;
        } else if(a[left] + a[right] > m) {
            right--;
        } else {
            res++;
            left++;
            right--;
        }
    }

    cout << res << endl;
}