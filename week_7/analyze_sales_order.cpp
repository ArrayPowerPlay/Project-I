#include <bits/stdc++.h>
using namespace std;

// Convert HH:MM:SS to seconds
int toSec(const string &s) {
    return stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int total_orders = 0;
    long long total_revenue = 0;
    map<string, int> shop_revene;
    map<pair<string, string>, int> revenue_customer_shop;
    // <timepoint, revenue>
    map<int, int> revenue_time_point;
    // <timepoint, revenue>
    // revenue up to timepoint (inclusive)
    map<int, int> prefix_sum;

    cin >> s;

    while(s != "#") {
        string prod, shopID, t;
        int price;

        cin >> prod >> price >> shopID >> t;

        ++total_orders;
        total_revenue += price;
        shop_revene[shopID] += price;
        revenue_customer_shop[{s, shopID}] += price;
        revenue_time_point[toSec(t)] += price;

        cin >> s;
    }

    int revenue = 0;

    for(auto &[t, rev] : revenue_time_point) {
        revenue += rev;
        prefix_sum[t] += revenue;
    }

    cin >> s;
    
    while(s != "#") {
        if(s == "?total_number_orders") {
            cout << total_orders << endl;
        } else if(s == "?total_revenue") {
            cout << total_revenue << endl;
        } else if(s == "?revenue_of_shop") {
            string shopID;
            cin >> shopID;
            
            cout << shop_revene[shopID] << endl;
        } else if(s == "?total_consume_of_customer_shop") {
            string cusID, shopID;
            cin >> cusID >> shopID;

            cout << revenue_customer_shop[{cusID, shopID}] << endl;
        } else {
            if(prefix_sum.empty()) cout << 0 << endl;
            else {
                string t1, t2;
                cin >> t1 >> t2;

                auto R = prefix_sum.upper_bound(toSec(t2));
                auto L = prefix_sum.upper_bound(toSec(t1) -1);
                
                int sumL = (L == prefix_sum.begin()) ? 0 : prev(L)->second;
                int sumR = (R == prefix_sum.begin()) ? 0 : prev(R)->second;

                cout << sumR - sumL << endl;
            }
        }

        cin >> s;
    }
}