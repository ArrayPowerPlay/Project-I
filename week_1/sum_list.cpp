// Given a sequence of integers a1, a2, ..., an. Compute the sum Q of elements of this sequence.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    unsigned int sum = 0;

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    cout << sum << endl;
}