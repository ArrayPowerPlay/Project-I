// Given a Text, write a prorgam to count the number Q of words
// (ignore characters SPACE, TAB, LineBreak) of this Text

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int cnt = 0;

    while(getline(cin, s)) {
        istringstream iss(s);
        while(iss >> s) {
            cnt++;
        }
    }

    cout << cnt << endl;
}