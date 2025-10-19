#include <bits/stdc++.h>
using namespace std;

void max_segment(const vector<int>& arr, int x, int y) {
    int max_seg = arr[x - 1];

    for(int i = x - 1; i <= y - 1; ++i) {
        max_seg = max(max_seg, arr[i]);
    }

    cout << max_seg << endl;
}

int main() {
    int n, max_int, min_int, sum = 0;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) {
            max_int = a[i];
            min_int = a[i];
        } else {
            max_int = max(max_int, a[i]);
            min_int = min(min_int, a[i]);
        }
        sum += a[i];
    }

    char s;
    cin >> s;
    if(s != '*') return 1;
    string str;
    cin.ignore();

    while(true) {
        getline(cin, str);
        if(str == "***") return 0;
        if(str == "find-max") {
            cout << max_int << endl;
        } else if(str == "find-min") {
            cout << min_int << endl;
        } else if(str == "sum") {
            cout << sum << endl;
        } else {
            if (str.substr(0, 16) == "find-max-segment") {
                istringstream iss(str);
                string ss;
                vector<int> b(2);
                int j = 0;

                while(iss >> ss) {
                    if (ss != "find-max-segment") {
                        b[j] = stoi(ss);
                        j++;
                    }
                }

                if(j == 2) max_segment(a, b[0], b[1]);
                else return 1;
            } else return 1;
        }
    }
}