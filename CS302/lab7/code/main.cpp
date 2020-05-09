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

int n;

class Cache {
public:
    int cache_size, cnt = 0;

    Cache(int size) {
        this->cache_size = size;
    }

    virtual void clear() = 0;

    int count() const {
        return this->cnt;
    }

    virtual bool contains(int v);

    virtual bool isFull();

    virtual void push(int v);

    virtual int pop();

    virtual void work() {
        this->clear();
        for (int i = 0; i < n; ++i) {
            this->push(read());
        }
    }
};

class Fifo_cache : public Cache {
    unordered_map<int, int> mp;
    queue<int> q;

public:
    Fifo_cache(int n) : Cache(n) {}

    void clear() override {
        this->cnt = 0;
        mp.clear();
        while (!q.empty()) {
            q.pop();
        }
    }

    bool contains(int v) override {
        return mp.find(v) != mp.end();
    }

    bool isFull() override {
        return q.size() == cache_size;
    }

    int pop() override {
        int x = q.front();
        q.pop();
        --mp[x];
    }

    void push(int v) override {
        if (this->contains(v)) {
            ++this->cnt;
        } else {
            if (isFull()) {
                this->pop();
            }
            q.push(v);
            ++mp[v];
        }
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

public:
    Lru_cache(int n) : Cache(n) {}

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


    bool contains(int v) override {
        return mp.find(v) != mp.end();
    }

    bool isFull() override {
        return mp.size() == cache_size;
    }

    int pop() override {
        node *tmp = tail;
        mp.erase(tmp->v);
        remove(tmp);
        delete tmp;
    }

    node* pop(int v) {
        auto pair = mp.find(v);
        if (pair != mp.end()) {
            remove(pair->second);
            return pair->second;
        }
        return nullptr;
    }


    void push(int v) override {
        node *now = pop(v);
        if (now == nullptr) {
            if (this->isFull()) {
                this->pop();
            }
            now = new node(v);
            mp[v] = now;
        } else {
            ++this->cnt;
        }
        insert(now);
    }
};

class Min_cache : public Cache {
    unordered_map<int, int> mp;
    priority_queue<pair<int, int> > pq;
    vector<int> a, nx;

public:
    Min_cache(int n) : Cache(n) {}

    void clear() override {
        this->cnt = 0;
        a.clear();
        nx.clear();
        mp.clear();
        while (!pq.empty()) {
            pq.pop();
        }
    }

    void push(int v, int next) {
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
        pq.push(make_pair(next, v));
    }

    void work() override {
        this->clear();
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
            this->push(a[i], nx[i]);
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

public:
    Clock_cache(int n) : Cache(n) {}

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
    Fifo_cache *fifoCache;
    Lru_cache *lruCache;

    map<int, int> mp;
    queue<int> q;
public:
    SecondChance_cache(int n) : Cache(n) {
        int hn = (n >> 1);
        this->fifoCache = new Fifo_cache(hn);
        this->lruCache = new Lru_cache(n - hn);
    }

    void clear() override {
        fifoCache->clear();
        lruCache->clear();
    }

    bool contains(int v) override {
        return fifoCache.contains(v) || lruCache.contains(v);
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

    void work() override {
        this->clear();
        for (int i = 0; i < n; ++i) {
            int v = read();
            if (fifoCache->contains(v)) {
                ++this->cnt;
                continue;
            }
            if (lruCache->contains(v)) {
                ++this->cnt;
                lruCache->pop(v);
                int tmp = fifoCache->pop();
                fifoCache->push(v);
                lruCache->push(tmp);
                continue;
            }
            if (!fifoCache->isFull()) {
                fifoCache->push(v);
                continue;
            }
            int tmp = fifoCache->pop();
            fifoCache->push(v);
            if (lruCache->isFull()) {
                lruCache->pop();
            }
            lruCache->push(tmp);
        }
    }
};


int main() {
    int cache_size = read();
    int algorithm = read();
    Cache *cache = nullptr;
    if (algorithm == 0) {
        cache = new Fifo_cache(cache_size);
    } else if (algorithm == 1) {
        cache = new Lru_cache(cache_size);
    } else if (algorithm == 2) {
        cache = new Min_cache(cache_size);
    } else if (algorithm == 3) {
        cache = new Clock_cache(cache_size);
    } else if (algorithm == 4) {
        cache = new SecondChance_cache(cache_size);
    }
    if (cache == nullptr) {
        puts("?");
        return 0;
    }
    n = read();
    cache->work();
    printf("Hit ratio = %05.2lf%%", (double) cache->count() / n * 100);
    return 0;
}
