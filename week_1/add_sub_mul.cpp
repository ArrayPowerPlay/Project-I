// Line 1 contains 2 integers a and b (1 <= a,b <= 1000)
// Write a+b, a-b, a*b, a/b  (4 integers are separated by a SPACE characters)

#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int a, b;
    cin >> a >> b;
    cout << a + b << " " << a - b << " " << a * b << " " << a / b << endl;
    return 0;
}