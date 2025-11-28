#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *next;

    node(int k) : val(k), next(nullptr) {}
};

// check if a node with value k exists in a linked list
bool check_exist(node *h, int k) {
    if(h == nullptr) return false;
    node *p = h;

    while(p != nullptr) {
        if(p->val == k) return true;
        p = p->next;
    }

    return false;
}

node *addlast(node *h, int k) {
    node *p = new node(k);

    if(h == nullptr) return p;

    node *tmp = h;
    if(check_exist(h, k)) return h;

    while(tmp->next != nullptr) {
        tmp = tmp->next;
    }

    tmp->next = p;
    return h;
}

node *addfirst(node *h, int k) {
    node *p = new node(k);

    if(h == nullptr) return p;
    if(check_exist(h, k)) return h;

    p->next = h;
    return p;
}

node *addafter(node *h, int u, int v) {
    if(check_exist(h, v) && !check_exist(h, u)) {
        node *p = h;
        
        while(p != nullptr) {
            if(p->val == v) {
                node *tmp = new node(u);
                
                tmp->next = p->next;
                p->next = tmp;
                return h;
            } 
            p = p->next;
        }
        return h;
    } 
    return h;
}

node *addbefore(node *h, int u, int v) {
    if(check_exist(h, v) && !check_exist(h, u)) {
        node *p = h;

        node *tmp = new node(u);
        if(p->val == v) {
            tmp->next = p;
            return tmp;
        }

        while(p->next != nullptr) {
            if(p->next->val == v) {
                tmp->next = p->next;
                p->next = tmp;
                return h;
            } 
            p = p->next;
        }
        return h;
    }
    return h;
}

node *remove(node *h, int k) {
    if(h == nullptr) return h;
    node *p = h;
    
    if(p->val == k) {
        p = p->next;
        return p;
    }

    while(p->next != nullptr) {
        if(p->next->val == k) {
            node *del = p->next;
            p->next = p->next->next;
            delete del;
            return h;
        } 
        p = p->next;
    }
    return h;
}

node *reverse(node *h) {
    if(h == nullptr) return h;
    node *prev = nullptr;
    node *cur = h;
    node *forward = nullptr;

    while(cur != nullptr) {
        forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
    }

    return prev;
}

void print_node(node *h) {
    if(h == nullptr) return;

    while(h != nullptr) {
        cout << h->val << " ";
        h = h->next;
    }
}

int main() {
    int n, x, y;
    string s;
    cin >> n;
    node *h = NULL;

    for(int i = 0; i < n; ++i) {
        cin >> x;
        h = addlast(h, x);
    }

    cin >> s;

    while(s != "#") {
        if(s == "addlast") {
            cin >> x;
            h = addlast(h, x);
        } else if(s == "addfirst") {
            cin >> x;
            h = addfirst(h, x);
        } else if(s == "addafter") {
            cin >> x >> y;
            h = addafter(h, x, y);
        } else if(s == "addbefore") {
            cin >> x >> y;
            h = addbefore(h, x, y);
        } else if(s == "remove") {
            cin >> x;
            h = remove(h, x);
        } else h = reverse(h);

        cin >> s;
    }

    print_node(h);
}