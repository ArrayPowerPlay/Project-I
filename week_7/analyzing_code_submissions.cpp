#include <bits/stdc++.h>
using namespace std;

// Convert string time to second
int total_sec(const string &t) {
    return stoi(t.substr(0, 2)) * 3600 + 
           stoi(t.substr(3, 2)) * 60 + 
           stoi(t.substr(6, 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int total_submissions = 0;
    int total_err_submissions = 0;
    map<string, int> count_errs_user;
    map<pair<string, string>, int> point_user;
    map<string, int> total_point_user;
    vector<int> sub_time;

    while(s != "#") {
        ++total_submissions;

        string prob, t, status;
        int point;

        cin >> prob >> t >> status >> point;

        if(status == "ERR") {
            ++total_err_submissions;
            ++count_errs_user[s];
        }

        int &curr_point = point_user[{s, prob}];

        if(curr_point < point) {
            total_point_user[s] += (point - curr_point);
            curr_point = point;
        }

        sub_time.push_back(total_sec(t));
        cin >> s;
    }

    cin >> s;
    sort(sub_time.begin(), sub_time.end());

    while(s != "#") {
        if(s == "?total_number_submissions") {
            cout << total_submissions << endl;
        } else if(s == "?number_error_submision") {
            cout << total_err_submissions << endl;
        } else if(s == "?number_error_submision_of_user") {
            string user;
            cin >> user;

            cout << count_errs_user[user] << endl;
        } else if(s == "?total_point_of_user") {
            string user;
            cin >> user;

            cout << total_point_user[user] << endl;
        } else {
            string t1, t2;
            int num_submissions = 0;
            cin >> t1 >> t2;

            auto L = lower_bound(sub_time.begin(), sub_time.end(), total_sec(t1));
            auto R = upper_bound(sub_time.begin(), sub_time.end(), total_sec(t2));

            cout << (R - L) << endl;
        }

        cin >> s;
    }
}