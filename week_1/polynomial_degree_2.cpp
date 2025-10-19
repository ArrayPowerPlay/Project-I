// Given an equation ax^2 + bx + c = 0. Find solution to the given equation.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if(a == 0) {
        if (b != 0) {
            double x = -1.0 * c / b;
            cout << fixed << setprecision(2) << x << endl;
        } else {
            cout << "NO SOLUTION" << endl;
        }
    } else {
        double delta = b * b - 4.0 * a * c;
        if (delta < 0) {
            cout << "NO SOLUTION" << endl;
        } else if (delta == 0) {
            double x = - b / (2.0 * a);
            cout << fixed << setprecision(2) << x << endl;
        } else {
            double x0 = (-b - sqrt(delta)) / (2.0 * a);
            double x1 = (-b + sqrt(delta)) / (2.0 * a);
            cout << fixed << setprecision(2) << x0 << " " << x1 << endl;
        }
    }
}