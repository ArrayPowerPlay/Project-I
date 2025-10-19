// Line 1: contains a positive integer n (1 <= n <= 999)
// Write the sequence of numbers found (elements are separated by a SPACE character)

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
    int n, i;
    cin >> n;  
    
    if(n < 100) i = (int) ceil(100.0/n) ;

    while(true) {
        int n_new = n * i; 

        if (n_new > 999) break;
        if (n_new * i >= 100 && n_new <= 999) {
            cout << n_new << " ";
        }

        i++;
    }
}