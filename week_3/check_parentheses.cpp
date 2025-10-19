#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    stack<char> st;
    int n = s.size();
    
    for(char c : s) {
        if(c == '{' || c == '(' || c == '[') {
            st.push(c);
        } else {
            if(st.empty()) return false;
            st.pop();
        }
    }

    if(!st.empty()) return false;
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << check(s) << endl;
}