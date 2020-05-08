#include <iostream>
#include <map>
#include <cstdio>
#include <unordered_map>
#include <queue>

using namespace std;

inline int read() {
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || '9' < ch) {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int cache_size = 100, n;

class Cache {
public:
    int cnt = 0;

    virtual void clear() = 0;

    int count() const {
        return this->cnt;
    }

    virtual void push(int v) = 0;

    virtual void work() {
        this->clear();
        n = read();
        for (int i = 0; i < n; ++i) {
            this->push(read());
        }
    }
};

class Fifo_cache : public Cache {
    unordered_map<int, int> mp;
    queue<int> q;

    void clear() override {
        this->cnt = 0;
        mp.clear();
        while (!q.empty()) {
            q.pop();
        }
    }

    void push(int v) override {
        if (mp[v]) {
            ++this->cnt;
            return;
        }
        if (q.size() == cache_size) {
            int x = q.front();
            q.pop();
            --mp[x];
        }
        q.push(v);
        ++mp[v];
    }
};

class Lru_cache : public Cache {
    struct node {
        int v;
        node *prev, *next;

        node(int v) {
            this->v = v;
            prev = next = nullptr;
        }
    };

    unordered_map<int, node *> mp;
    node *head, *tail;

    void clear() override {
        this->cnt = 0;
        mp.clear();
        head = tail = nullptr;
    }

    void insert(node *now) {
        now->next = head;
        if (head == nullptr) {
            head = tail = now;
        } else {
            head->prev = now;
            now->next = head;
            now->prev = nullptr;
            head = now;
        }
    }

    void remove(node *now) {
        if (now->prev == nullptr)
            head = now->next;
        else
            now->prev->next = now->next;
        if (now->next == nullptr)
            tail = now->prev;
        else
            now->next->prev = now->prev;
    }

    void push(int v) override {
        auto pair = mp.find(v);
        node *now;
        if (pair != mp.end()) {
            now = pair->second;
            ++this->cnt;
            remove(now);
        } else {
            now = new node(v);
            if (mp.size() == cache_size) {
                node *tmp = tail;
                mp.erase(tmp->v);
                remove(tmp);
                delete tmp;
            }
            mp[v] = now;
        }
        insert(now);
    }
};

class Min_cache : public Cache {
    unordered_map<int, int> mp;
    priority_queue<pair<int, int> > pq;
    vector<int> a, nx;

    void clear() override {
        this->cnt = 0;
        a.clear();
        nx.clear();
        mp.clear();
        while (!pq.empty()) {
            pq.pop();
        }
    }

    void push(int v) override {
    }

    void work() override {
        this->clear();
        n = read();
        for (int i = 0; i < n; ++i) {
            a.push_back(read());
            nx.push_back(0x7fffffff);
        }
        for (int i = n - 1; i >= 0; --i) {
            auto pair = mp.find(a[i]);
            if (pair != mp.end()) {
                nx[i] = pair->second;
            }
            mp[a[i]] = i;
        }
        mp.clear();
        for (int i = 0; i < n; ++i) {
            int v = a[i];
            auto pair = mp.find(v);
            if (pair != mp.end()) {
                ++this->cnt;
            } else {
                if (mp.size() == cache_size) {
                    auto tp = pq.top();
                    pq.pop();
                    mp.erase(tp.second);
                }
                mp[v] = 1;
            }
            pq.push(make_pair(nx[i], v));
        }
    }

};

class Clock_cache : public Cache {
    struct node {
        int v;
        bool valid = false;
        node *prev, *next;

        node(int v) {
            this->v = v;
            prev = next = nullptr;
            valid = false;
        }
    };

    unordered_map<int, node *> mp;
    node *ptr;

    void clear() override {
        this->cnt = 0;
        mp.clear();
        ptr = nullptr;
    }

    void insert(node *now) {
        if (ptr == nullptr) {
            now->prev = now->next = now;

            ptr = now;
        } else {
            now->next = ptr;
            now->prev = ptr->prev;

            ptr->prev->next = now;
            ptr->prev = now;
        }
    }

    void remove(node *now) {
        if (now->prev != nullptr)
            now->prev->next = now->next;
        if (now->next != nullptr)
            now->next->prev = now->prev;
        if (now == ptr)
            ptr = now->next;
    }

    void push(int v) override {
        auto pair = mp.find(v);
        node *now;
        if (pair != mp.end()) {
            now = pair->second;
            ++this->cnt;
        } else {
            now = new node(v);
            if (mp.size() == cache_size) {
                node *tmp = ptr;
                while (tmp != nullptr && tmp->valid) {
                    tmp->valid = false;
                    tmp = tmp->next;
                }
                ptr = tmp->next;
                mp.erase(tmp->v);
                remove(tmp);
                delete tmp;
            }
            mp[v] = now;
            insert(now);
        }
        now->valid = true;
    }
};

class SecondChance_cache : public Cache {
    map<int, int> mp;
    queue<int> q;

    void clear() override {
        this->cnt = 0;
        mp.clear();
        while (!q.empty()) {
            q.pop();
        }
    }

    void push(int v) override {
        if (mp[v]) {
            ++this->cnt;
            return;
        }
        if (q.size() == cache_size) {
            int x = q.front();
            q.pop();
            --mp[x];
        }
        q.push(v);
        ++mp[v];
    }
};


int main() {
    cache_size = read();
    int algorithm = read();
    Cache *cache = nullptr;
    if (algorithm == 0) {
        cache = new Fifo_cache;
    } else if (algorithm == 1) {
        cache = new Lru_cache;
    } else if (algorithm == 2) {
        cache = new Min_cache;
    } else if (algorithm == 3) {
        cache = new Clock_cache;
    } else if (algorithm == 4) {
        cache = new SecondChance_cache;
    }
    if (cache == nullptr) {
        puts("?");
        return 0;
    }
    cache->work();
    printf("Hit ratio = %05.2lf%%", (double) cache->count() / n * 100);
    return 0;
}