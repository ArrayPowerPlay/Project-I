#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
unordered_map<string, unordered_set<string>> adj;
unordered_map<string, bool> visited;

// Function used to inspect cycles
bool dfs(string curr, const string &start, const int &k, int curr_len) {
    for (auto &ss : adj[curr]) {
        if (!visited[ss]) {
            visited[ss] = true;
            ++curr_len;
            
            if (curr_len == k - 1) {
                if (adj[ss].find(start) != adj[ss].end()) {
                    return true;
                }
            } else {
                if (dfs(ss, start, k, curr_len)) {
                    return true;
                }
            }
            
            // Backtrack
            --curr_len;
            visited[ss] = false;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int total_transactions = 0;
    ll total_money_transactions = 0;
    set<string> accounts;
    map<string, ll> money_trans_from;

    cin >> s;

    while(s != "#") {
        string to_account, t, atm;
        int money;

        cin >> to_account >> money >> t >> atm;

        ++total_transactions;
        total_money_transactions += money;
        accounts.insert(s);
        accounts.insert(to_account);
        money_trans_from[s] += money;

        adj[s].insert(to_account);
        visited[s] = false;
        visited[to_account] = false;

        cin >> s;
    }

    cin >> s;

    while(s != "#") {
        if(s == "?number_transactions") {
            cout << total_transactions << endl;
        } else if(s == "?total_money_transaction") {
            cout << total_money_transactions << endl;
        } else if(s == "?list_sorted_accounts") {
            for(auto &account : accounts) {
                cout << account << " ";
            }
        } else if(s == "?total_money_transaction_from") {
            string account;
            cin >> account;
            
            cout << money_trans_from[account] << endl;
        } else {
            string account;
            int cyc_len;
            cin >> account >> cyc_len;
            
            for (auto &p : visited) p.second = false;
            visited[account] = true;

            cout << (dfs(account, account, cyc_len, 0) ? 1 : 0) << endl;
        }

        cin >> s;
    }
}