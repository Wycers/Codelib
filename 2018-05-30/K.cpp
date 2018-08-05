#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
const int N = 1e5 + 10;

struct edge_
{
    int to, next, w;
} edge[2 * N], query[2 * N];
int head[N], head1[N], cnt = 0, cnt1 = 0;
void insert(int u, int v, int w)
{
    edge[++cnt] = (edge_){v, head[u], w};
    head[u] = cnt;
}
void insert1(int u, int v, int w)
{
    edge1[++cnt1] = (edge_){v, head1[u], w};
    head1[u] = cnt1;
}
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}
queue<int> q; 
bool inq[N]; int dis[N];
void spfa(int x)
{
    memset(inq, false, sizeof(inq));
    memset(dis,  0x3f, sizeof(dis));
    q.push(x); inq[x] = true; dis[x] = 0;
    while (!q.empty())
    {
        int now = q.front();
        for (int i = head[now]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dis[v] > dis[now] + edge[i].w)
            {
                dis[v] = dis[now] + edge[i].w;
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
int n, Q, x[N], y[N], tag[N], du[N];
vector<int> vec[N];

multimap<pair<int, int> , int> mp;
multimap<pair<int, int> , int>::iterator beg, end;
priority_queue<int, vector<int>, cmp> pq;
struct cmp{  
    bool operator() (const int& a, const int& b ){  
        return du[a] > du[b];
    }  
};   
set<int> s;
void clean()
{
    memset(head, 0, sizeof(head));
    memset(du, 0, sizeof(du));
    cnt = 0;
    for (int i = 1; i <= n; ++i)
        vec[i].clear();
    for (int i = 1; i <= n; ++i)
        tag[i] = i;
}
bool cmp(const int &a, const int &b)
{
    return du[a] > du[b];
}
void solve()
{
    n = read(); Q = read();
    clean();
    for (int i = 1; i <= n; ++i)
    {
        int u = read(); int v = read(); int w = read();
        insert(u, v, w);
        insert(v, u, w);
    }
    for (int i = 1; i <= Q; ++i)
    {
        x[i] = read(); y[i] = read();
        ++du[x[i]]; ++du[y[i]];
        insert1(x[i], y[i], 1);
    }
    for (int i = 1; i <= n; ++i)
        pq.push(i);
    while (!q.empty())
    {
        
    }
}
int main()
{
    for (int T = read(); T; --T)
        solve();
    return 0;
}