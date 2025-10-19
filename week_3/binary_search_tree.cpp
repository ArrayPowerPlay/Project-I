#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *leftChild;
    node *rightChild;

    node(int v) : val(v), leftChild(NULL), rightChild(NULL) {}
};

// check if node v exists in a BST
bool check_node(node *h, int v) {
    if(h == NULL) return false;
    if(h->val == v) return true;

    bool left = check_node(h->leftChild, v);
    bool right = check_node(h->rightChild, v);

    return left || right;
}

void insert(node *&h, int v) {
    node *value = new node(v);

    if(h == NULL) {
        h = value;
        return;
    }
    if(check_node(h, v)) return;
    if(v < h->val) insert(h->leftChild, v);
    else insert(h->rightChild, v);
    
}

void pre_order_tranversal(node *h) {
    if(h == NULL) return;
    cout << h->val << " ";
    pre_order_tranversal(h->leftChild);
    pre_order_tranversal(h->rightChild);
}

int main() {
    string s;
    int v;
    node *h = NULL;

    cin >> s;
    while(s != "#") {
        cin >> v;
        insert(h, v);

        cin >> s;
    }

    pre_order_tranversal(h);
}