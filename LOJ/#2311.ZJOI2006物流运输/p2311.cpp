#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110, M = 25;
const int Inf = 0x3f3f3f3f;

int read() {
    char ch = getchar(); int f = 1, x = 0;
    while (ch < '0' || '9' < ch) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}


struct edge_ {
    int to, next, w;
} edge[M * M];
int head[M], cnt = 0;
void insert(int u, int v, int w) {
    edge[++cnt] = (edge_){v, head[u], w};
    head[u] = cnt; 
}

int n, m, k, status[N], dis[M], cost[N][N];
queue<int> q;
bool inq[N];
int spfa(int l, int r) {
    if (cost[l][r] != -1)
        return cost[l][r];
    memset(inq, false, sizeof(inq));
    memset(dis,  0x3f, sizeof(dis));
    q.push(1); inq[1] = true; dis[1] = 0;
    int set = 0;
    for (int i = l; i <= r; ++i) 
        set |= status[i];
    while (!q.empty()) {
        int now = q.front(); 
        for (int i = head[now]; i; i = edge[i].next) {
            int v = edge[i].to;
            if (set & (1 << v))
                continue;
            if (dis[v] > dis[now] + edge[i].w) {
                dis[v] = dis[now] + edge[i].w;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
        q.pop(); inq[now] = false;
    }
    cost[l][r] = dis[m];
    return dis[m];
}

void readin() {
    n = read(); m = read(); k = read();
    int u, v, w;
    for (int e = read(); e; e--) {
        u = read(); v = read(); w = read();
        insert(u, v, w);
        insert(v, u, w);
    }
    int p, l, r;
    memset(status, 0, sizeof(status));
    for (int d = read(); d; d--) {
        p = read(); l = read(); r = read();
        for (int i = l; i <= r; ++i) 
            status[i] |= (1 << p);
    }
}

int f[N];
void dp() {
    memset(cost, 0xff, sizeof(cost));
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        f[i] = Inf;
        if (spfa(1, i) != Inf)
            f[i] = min(f[i], spfa(1, i) * i);
        for (int j = 0; j < i; ++j) 
            if (spfa(j + 1, i) != Inf)
                f[i] = min(f[i], f[j] + spfa(j + 1, i) * (i - j) + k);
    }
    printf("%d", f[n]);
}

int main() {
    readin();
    dp();
    return 0;
}