// Input:
// Line 1: contains a string s representing the time moment.  
// Output:
// Convert this time moment in seconds (result = hh*3600 + mm*60 + ss).
// If s is not under the format hh:mm:ss, then write INCORRECT. Otherwise, write value converted.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    if (str.size() != 8 || str[2] != ':' || str[5] != ':') {
        cout << "INCORRECT" << endl;
    } else {
        if (isdigit(str[0]) && isdigit(str[1]) && isdigit(str[3])
         && isdigit(str[4]) && isdigit(str[6]) && isdigit(str[7])) {
            int h = stoi(str.substr(0, 2));
            int m = stoi(str.substr(3, 2));
            int s = stoi(str.substr(6, 2));
            if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
                cout << h * 3600 + m * 60 + s << endl;
            } else {
                cout << "INCORRECT" << endl;
            }
        } else {
            cout << "INCORRECT" << endl;
        }
    }
}