//

#include <bits/stdc++.h>
using namespace std;

int main() {
    string p1, p2, t;
    
    getline(cin, p1);
    getline(cin, p2);
    getline(cin, t);
    int len = p2.size();
    int n = t.size();
    int i = 0;
    
    while(i < n) {
        int pos = t.find(p1, i);

        if(pos != -1) {
            int k = pos + p1.size();
            if(k < n) {
                string left = t.substr(k, n - k + 1);
                t.replace(pos, len, p2);
                i = pos + len;
                t = t.substr(0, i) + left;
                n = t.size();
            } else {
                t.replace(pos, len, p2);
                break;
            }
        } else break;
    }

    cout << t << endl;

}