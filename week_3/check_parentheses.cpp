#include <bits/stdc++.h>
using namespace std;

bool check(const string &s) {
    stack<char> st;
    
    for(char c : s) {
        if(c == '(' || c == '[' || c == '{') st.push(c);
        else {
            if(st.empty()) return false;
            char cc = st.top();
            st.pop();
            if((cc == '(' && c != ')') || (cc == '{' && c != '}') || (cc == '[' && c != ']')) return false;
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