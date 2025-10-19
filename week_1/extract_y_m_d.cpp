// Input:
// Line 1: contains a string s  
// Ouput:
// If s is not under the format YYYY-MM-DD, then write INCORRECT. Otherwise, write year, month, and date separated by a SPACE character

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    if(str.size() != 10 || str[4] != '-' || str[7] != '-') {
        cout << "INCORRECT" << endl;
    } else {
        if (isdigit(str[0]) && isdigit(str[1]) && isdigit(str[2]) && isdigit(str[3])
         && isdigit(str[5]) && isdigit(str[6]) && isdigit(str[8]) && isdigit(str[9])) {
            int y = stoi(str.substr(0, 4));
            int m = stoi(str.substr(5, 2));
            int d = stoi(str.substr(8, 2));
            if (y >= 0 && m >= 1 && m <= 12 && d >= 1 && d <= 31) {
                cout << y << " " << m << " " << d << endl;
            } else {
                cout << "INCORRECT" << endl;
            }
        } else {
            cout << "INCORRECT" << endl;
        }
    }
}