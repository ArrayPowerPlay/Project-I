#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *leftChild;
    Node *rightChild;
    Node(int v): val(v), leftChild(nullptr), rightChild(nullptr) {}
};

bool checkExist(Node *head, int v) {
    if(head == nullptr) return false;
    if(head->val == v) return true;

    bool left = checkExist(head->leftChild, v);
    bool right = checkExist(head->rightChild, v);
    return left || right;
}

void insert(Node *&head, int v) {
    Node *p = new Node(v);
    if(head == nullptr) {
        head = p;
        return;
    }
    if(checkExist(head, v)) return;
    if(v <= head->val) {
        insert(head->leftChild, v);
    } else {
        insert(head->rightChild, v);
    }
}

void preOrder(Node *head) {
    if(head == nullptr) return;
    cout << head->val << " ";
    preOrder(head->leftChild);
    preOrder(head->rightChild);
}

void inOrder(Node *head) {
    if(head == nullptr) return;
    
    preOrder(head->leftChild);
    cout << head->val << " ";
    preOrder(head->rightChild);
}

void postOrder(Node *head) {
    if(head == nullptr) return;
    
    preOrder(head->leftChild);
    preOrder(head->rightChild);
    cout << head->val << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s;
    cin >> s;
    Node *head = nullptr;
    
    while(s != "*") {
        if(s == "insert") {
            int v;
            cin >> v;
            insert(head, v);
        } else if(s == "PreOrder") {
            preOrder(head);
        } else if(s == "InOrder") {
            inOrder(head);
        } else {
            postOrder(head);
        }
        cin >> s;
    }
}