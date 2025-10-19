// Given a sequence of integer a1, a2, ..., an. 
// Count the number of odd elements and even elements of the sequence.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int odd = 0, even = 0;

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) even++;
        else odd++;
    }

    cout << odd << " " << even << endl;
}
