// Line 1: contains a positive integer n (1 <= n <= 100)
// Each line i (i = 1,...,n): contains i and i^2 (elements are separated by one SPACE character)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cout << i << " " << i * i << endl;
    }
}