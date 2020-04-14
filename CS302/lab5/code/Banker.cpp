//
// Created by Wycer on 2020/4/14.
//


#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vint;
int n;

void debug(vint *vec) {
    for (auto i:*vec) {
        cout << i << " ";
    }
    cout << endl;
}

struct node {
    vint *used, *max;
    node *prev, *next;
    bool dealt = false;

    node(const string &name, vint *vec) {
        this->max = vec;
        this->used = new vector<int>(n);
        for (int i = 0; i < n; ++i) {
            this->used->at(i) = 0;
        }

        this->prev = this->next = nullptr;
    }

    ~node() {
        delete (used);
        delete (max);
    }
} *head;

vint *used, *all;
map<string, node *> mp;

vint *operator-(const vint &a, const vint &b) {
    vint *res = new vint(n);
    for (int i = 0; i < n; ++i)
        res->at(i) = a[i] - b[i];
    return res;
}

vint &operator+=(vint &a, const vint &b) {
    for (int i = 0; i < n; ++i)
        a[i] += b[i];
    return a;
}

vint &operator-=(vint &a, const vint &b) {
    for (int i = 0; i < n; ++i)
        a[i] -= b[i];
    return a;
}

bool satisfy(const vint &a, const vint &b) {
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i])
            return false;
    }
    return true;
}

vint *read_vector() {
    vint *vec = new vector<int>;
    for (int i = 0, tmp; i < n; ++i) {
        cin >> tmp;
        vec->push_back(tmp);
    }
    return vec;
}

void ins(const string &name, vector<int> *vec) {
    node *now = new node(name, vec);

    node *h = head;
    head = now;

    now->prev = nullptr;

    now->next = h;
    if (h != nullptr) {
        h->prev = now;
    }
    mp[name] = now;
}

void del(node *now) {
    *used -= *now->used;

    if (now->prev != nullptr) {
        now->prev->next = now->next;
    }
    if (now->next != nullptr) {
        now->next->prev = now->prev;
    }
    if (now == head) {
        head = now->next;
    }
    delete now;
}


bool verify(node *now, vint *vec) {
    for (int i = 0; i < n; ++i) {
        if (now->used->at(i) + vec->at(i) > now->max->at(i))
            return false;
        if (used->at(i) + vec->at(i) > all->at(i))
            return false;
    }
    return true;
}

bool isSafe(vint *rest) {
    bool flag = true;
    for (node *now = head; now != nullptr; now = now->next) {
        if (now->dealt)
            continue;
        flag = false;
        break;
    }
    if (flag) {
        return true;
    }

    for (node *now = head; now != nullptr; now = now->next) {
        if (now->dealt)
            continue;
        vint *delta = *(now->max) - *(now->used);


//        debug(delta);

        if (!satisfy(*rest, *delta)) {
            delete delta;
            continue;
        }

        now->dealt = true;
        *rest += *now->used;
        if (isSafe(rest)) {
            delete delta;
            return true;
        }
        *rest -= *now->used;
        now->dealt = false;
        delete delta;
    }
    return false;
}

bool isSafe(node *now, vint *vec) {
    *now->used += *vec;
    vint *rest = *all - *used;
    *rest -= *vec;

    debug(rest);

    bool res = isSafe(rest);

    delete rest;
    for (node *i = head; i != nullptr; i = i->next) {
        i->dealt = false;
    }

    return res;
}


int main() {
    cin >> n;
    all = read_vector();
    used = new vint(n, 0);

    string name, opt;
    while (cin >> name >> opt) {
        cout << name << " " << opt << endl;
        if (opt == "new") {
            node *now = mp[name];
            if (now == nullptr) {
                printf("Initialize %s twice.\n", name.c_str());
                return -1;
            }
            vint *vec = read_vector();
            bool flag = true;
            for (int i = 0; i < n; ++i)
                if (vec->at(i) > all->at(i)) {
                    flag = false;
                    break;
                }
            if (flag) {
                ins(name, vec);
                puts("OK");
            } else {
                puts("NOT OK");
            }
        } else if (opt == "request") {
            node *now = mp[name];
            vint *vec = read_vector();
            if (!verify(now, vec)) {
                puts("NOT OK");
                continue;
            }
            if (!isSafe(now, vec)) {
                puts("NOT OK");
                continue;
            }
            *used += *vec;
            puts("OK");
        } else if (opt == "terminate") {
            node *now = mp[name];
            if (now == nullptr) {
                printf("%s does not exist.\n", name.c_str());
                return -1;
            } else {
                del(now);
                mp.erase(name);
                puts("OK");
            }
        }
    }
    return 0;
}
