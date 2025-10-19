// Convert input text to uppercase

#include <bits/stdc++.h>
using namespace std;

void convert_upper(string &s) {
    for(char &c : s) {
        c = toupper(c);
    }
}

int main() {
    string s;
    
    while(getline(cin, s)) {
        convert_upper(s);
        cout << s << endl;
    }
}