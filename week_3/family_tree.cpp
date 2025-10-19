#include <bits/stdc++.h>
using namespace std;

struct node {
    string name;
    vector<node*> childs;

    node(string s) : name(s) {}
};

void add_child(node *&h, string child_name) {
    node *child = new node(child_name);

    if(h == NULL) {
        h = child;
        return;
    }

    h->childs.push_back(child);
}

// find out if a child belongs to a parent whose node is h
node *find_child(node *h, string child_name) {
    if(h == NULL) return NULL;
    if(h->name == child_name) return h;

    for(auto child : h->childs) {
        node *found = find_child(child, child_name);
        if(found != NULL) {
            return found;
        }
    }
    return NULL;
}

void add_child(node *&h, string child_name, string parent_name) {
    if (h == NULL) {
        h = new node(parent_name);
        h->childs.push_back(new node(child_name));
        return;
    }

    node *parent = find_child(h, parent_name);
    node *child  = find_child(h, child_name);

    if (parent == NULL) {
        parent = new node(parent_name);

        if (child != NULL) {
            parent->childs.push_back(child);
        } else {
            parent->childs.push_back(new node(child_name));
        }

        h->childs.push_back(parent);
        return;
    }

    if (child == NULL) {
        parent->childs.push_back(new node(child_name));
    } else {
        parent->childs.push_back(child);
    }
}


int count_descendants(node *h, string person) {
    node *p = find_child(h, person);
    if(p == NULL) return 0;

    int cnt = 0;
    queue<node*> q;
    q.push(p);

    while(!q.empty()) {
        node *h = q.front();
        q.pop();

        for(auto child : h->childs) {
            q.push(child);
            ++cnt;
        }
    }
    return cnt;
}

int count_depth(node *h) {
    if(h == NULL) return -1;
    int res = -1;    

    for(auto child : h->childs) {
        res = max(res, count_depth(child));
    }

    return ++res;
}

int count_generation(node *h, string person) {
    node *p = find_child(h, person);
    if(p == NULL) return 0;
    return count_depth(p);
}

int main() {
    node *oldest = new node("TTT");
    string child, parent, person;

    cin >> child;
    while(child != "***") {
        cin >> parent;
        add_child(oldest, child, parent);

        cin >> child;
    }

    cin >> child;
    while(child != "***") {
        if(child == "descendants") {
            cin >> person;
            cout << count_descendants(oldest, person) << endl;
        } else {
            cin >> person;
            cout << count_generation(oldest, person) << endl;
        }

        cin >> child;
    }
}