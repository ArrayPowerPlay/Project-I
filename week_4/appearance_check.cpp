// Given a sequence of integers A1, A2, . . . , An, for each integer Ai
// checks whether there is a number Aj equal to Ai or not with j<i
// Input
// First line contains number n (1≤n≤100,000)
// Second line contains nn integers A1, A2, ..., An (1≤Ai≤1000,000,000)
// Output
// Write n lines, the i-th line prints 1 if Aj=Ai exists with j<i, otherwise print 0

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> a(n);
    // M[i] = check if there is any j < i such that a[j] = a[i]
    vector<int> M(n);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];

        if(i == 0) M[i] = 0;
        else {
            M[i] = i;
        }
    }
    
}