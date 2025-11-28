#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    vector<Node*> childs;
    Node(int v): val(v) {}
};

void makeRoot(Node *&h, int v) {
    h = new Node(v);
}

Node *checkExist(Node *h, int v) {
    if(h == nullptr) return nullptr;
    if(h->val == v) return h;

    for(Node *child : h->childs) {
        Node *check = checkExist(child, v);
        if(check != nullptr) return check;
    }
    return nullptr;
}

void insert(Node *h, int u, int v) {
    Node *p = new Node(u);
    Node *check_v = checkExist(h, v);
    Node *check_u = checkExist(h, u);
    if(check_v != nullptr && check_u == nullptr) {
        Node *q = checkExist(h, v);
        q->childs.push_back(p);
    }
}

void preOrder(Node *h) {
    if(h == nullptr) return;
    cout << h->val << " ";
    for(Node *child : h->childs) {
        preOrder(child);
    }
}

void inOrder(Node *h) {
    if(h == nullptr) return;
    int n = h->childs.size();
    if(n == 0) {
        cout << h->val << " ";
        return;
    }
    
    inOrder(h->childs[0]);
    cout << h->val << " ";
    for(int i = 1; i < n; ++i) {
        inOrder(h->childs[i]);
    }
}

void postOrder(Node *h) {
    if(h == nullptr) return;
    
    for(Node *child : h->childs) {
        postOrder(child);
    }
    cout << h->val << " ";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s;
    cin >> s;
    Node *head = nullptr;
    
    while(s != "*") {
        if(s == "MakeRoot") {
            int x;
            cin >> x;
            makeRoot(head, x);
        } else if(s == "Insert") {
            int u, v;
            cin >> u >> v;
            insert(head, u, v);
        } else if(s == "PreOrder") {
            preOrder(head);
            cout << "\n";
        } else if(s == "InOrder") {
            inOrder(head);
            cout << "\n";
        } else {
            postOrder(head);
            cout << "\n";
        }
        cin >> s;
    }
}