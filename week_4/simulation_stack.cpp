#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int x;
    stack<int> st;
    cin >> s;

    while(s != "#") {
        if(s == "PUSH") {
            cin >> x;
            st.push(x);
        } else {
            if(st.empty()) cout << "NULL" << endl;
            else {
                x = st.top();
                st.pop();
                cout << x << endl;
            }
        }

        cin >> s;
    }
}