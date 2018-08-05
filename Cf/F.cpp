#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<string>
#include<vector>
#include<bitset>
#include<memory>
#include<cstdio>
#include<utility>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#pragma optimize("-O3")

#ifdef Wavator

#define Debug(...) fprintf(stderr, __VA_ARGS__);

#else

#define Debug(...) 98;

#define cerr if (false) cout

#endif

typedef long long ll;

template <typename A> inline void read(A &x) {
    bool f = false;
    x = 0;
    char c;
    for (c = getchar(); !isdigit(c); c = getchar()) {
        if (c == '-') {
            f = true;
        }
    }
    for (; isdigit(c); c = getchar()) {
        x = (x << 1) + (x << 3) + c - '0';
    }
    if (f) {
        x = -x;
    }
}

template <typename A, typename B> inline void read(A &a, B & b) {
    read(a);
    read(b);
}

template <typename A, typename B, typename C> inline void read(A &a, B &b, C &c) {
    read(a);
    read(b);
    read(c);
}

#define pb push_back

#define all(x) x.begin(), x.end()

const int N = 1e5 + 10;
int a, n, m, pos[N], w[N], l[N], r[N];

struct Edge
{
    int to, next, w;
} edge[];
int head[2005], cnt = 0;
void insert(int u, int v, int w)
{
    edge[++cnt] = (Edge){v, head[u], w};
    head[u] = cnt;
}
int dis[N]; bool inq[N];
queue<int> q;
void spfa()
{
    for (int i = 0; i <= a; ++i)
        dis[i] = 0x3f3f3f3f;
    q.push(0); inq[0] = true; dis[0] = 0;
    while (!q.empty())
    {
        int now = q.front(); 
        for (int i = head[now]; i; i =edge[i].next)
        {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w)
            {
                dis[v] = dis[u] + edge[i].w;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
        q.pop(); inq[now] = false;
    }
}

int tag[N];
bool cmp(int a ,int b)
{
    return l[a] < l[b];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    read(a, n, m);
    for (int i = 1; i <= n; ++i)
        read(l[i], r[i]);
    for (int i = 1; i <= m; ++i)
        read(pos[i], w[i]);

    int min1 = 0x3f3f3f3f, min2 = 0x3f3f3f3f;
    for (int i = 1; i <=n ;++i)
        min1 = min(min1, l[i]);
    for (int i = 1; i <= m; ++i)
        min2 = min(min2, pos[i]);
    if (min1 < min2)
    {
        puts("-1");
        return 0;
    }
    
    for (int i = 1; i <= n; ++i)
        tag[i] = i;
    sort(tag + 1, tag + n +1, cmp);
    for (int i = 1; i < n; ++i)
        for (int j = r[tag[i]]; j <= l[tag[i + 1]]; ++j)
            insert(j, j + 1, 0);
    for (int i = 0; i < l[tag[1]]; ++i)
        insert(i, i + 1, 0);
    for (int i = r[tag[n]]; i < n; ++i)
        insert(i, i + 1, 0);
    
    



    printf("%d\n", getans(a));
    return 0;
}