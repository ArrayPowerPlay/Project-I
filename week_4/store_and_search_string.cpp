#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, item;
    cin >> s;
    set<string> st;

    while(s != "*") {
        st.insert(s);
        cin >> s;
    }

    cin >> s;

    while(s != "***") {
        cin >> item;
        if(s == "find") {
            if(st.find(item) != st.end()) cout << 1 << endl;
            else cout << 0 << endl;
        } else {
            if(st.find(item) != st.end()) cout << 0 << endl;
            else {
                cout << 1 << endl;
                st.insert(item);
            }
        }

        cin >> s;
    }
}