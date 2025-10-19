#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    vector<Node*> children;

    Node(int _id): id(_id) {}
};

map<int, Node*> nodes;
int root_id;

void make_root(int u) {
    if(nodes.count(u)) return;
    Node *p = new Node(u);
    nodes[u] = p;
    root_id = u;
}

void insert(int u, int v) {
    if(nodes.count(v) == 0 || nodes.count(u) > 0) {
        return;
    }
    Node *p = new Node(u);
    nodes[v]->children.push_back(p);
    nodes[u] = p;
}

void pre_oder(int root) {
    Node *p = nodes[root];
    cout << root << " ";
    for(auto child : p->children) {
        pre_oder(child->id);
    }
}

void in_order(int root) {
    Node *p = nodes[root];
    int n = p->children.size();
    if(n == 0) {
        cout << root << " ";
        return;
    }

    in_order((p->children)[0]->id);

    cout << root << " ";

    for(int i = 1; i < n; ++i) {
        in_order((p->children)[i]->id);
    }
}

void post_oder(int root) {
    Node *p = nodes[root];
    for(auto child : p->children) {
        post_oder(child->id);
    }
    cout << root << " ";
}

int main() {
    string s;
    cin >> s;
    int x, y;

    while(s != "*") {
        if(s == "MakeRoot") {
            cin >> x;
            make_root(x);
        } else if(s == "Insert") {
            cin >> x >> y;
            insert(x, y);
        } else if(s == "PreOrder") {
            pre_oder(root_id);
            cout << endl;
        } else if(s == "InOrder") {
            in_order(root_id);
            cout << endl;
        } else {
            post_oder(root_id);
            cout << endl;
        }

        cin >> s;
    }
}