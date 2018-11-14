#include <cstdio>
#include <algorithm>
#include <cmath>
const int N = 100000 + 10;
using namespace std;
int Read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
struct edge
{
    int to,next;
} e[2 * N];
int head[N],cnt = 0;
void Insert(int u,int v)
{
    e[++cnt] = (edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (edge){u,head[v]};head[v] = cnt;
}

int id = 0,fa[N],pos[N],size[N],belong[N],mx[N],v[N];
long long tag[4 * N],sum[4 * N],n,m;
bool vis[N];
void Dfs1(int now)
{
    int v;
    size[now] = 1;
    for (int i=head[now];i;i=e[i].next)
    {
        v = e[i].to;
        if (v != fa[now])
        {
            fa[v] = now;
            Dfs1(v);
            size[now] += size[v];
            mx[now] = max(mx[now],mx[v]);
        }
    }
}
void Dfs2(int now,int chain)
{
    belong[now] = chain;
    pos[now] = mx[now] = ++id;
    int tag = 0,v;
    for (int i=head[now];i;i=e[i].next)
    {
        v = e[i].to;
        if (v != fa[now] && size[v] > size[tag])
            tag = v;
    }
    if (tag)
    {
        Dfs2(tag,chain);
        mx[now] = max(mx[now],mx[tag]);
    }
    for (int i=head[now];i;i=e[i].next)
    {
        v = e[i].to;
        if (v != fa[now] && v != tag)
        {
            Dfs2(v,v);
            mx[now] = max(mx[now],mx[v]);
        }
    }
}
void Pushdown(int k,int l,int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    long long t = tag[k];tag[k] = 0;
    tag[k << 1] += t;tag[k << 1 | 1] += t;
    sum[k << 1] += t * (mid - l + 1);
    sum[k << 1 | 1] += t * (r - mid);
}
void Add(int k,int l,int r,int x,int y,long long val)
{
    if (tag[k]) Pushdown(k,l,r);
    if (l == x && r == y)
    {
        tag[k] += val;
        sum[k] += (r - l + 1) * val;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) Add(k << 1,l,mid,x,min(mid,y),val);
    if (mid < y) Add(k << 1 | 1,mid + 1,r,max(mid + 1,x),y,val);
    sum[k] = sum[k << 1] + sum[k << 1 | 1];
}
long long Query(int k,int l,int r,int x,int y)
{
    if (tag[k]) Pushdown(k,l,r);
    if (l == x && r == y)
        return sum[k];
    int mid = (l + r) >> 1;long long temp = 0;
    if (x <= mid)
        temp += Query(k << 1,l,mid,x,min(mid,y));
    if (mid < y)
        temp += Query(k << 1 | 1,mid + 1,r,max(mid + 1,x),y);
    return temp;
}
long long Query(int x)
{
    long long ans = 0;
    while (belong[x] != 1)
    {
        ans += Query(1,1,n,pos[belong[x]],pos[x]);
        x = fa[belong[x]];
    }
    ans += Query(1,1,n,1,pos[x]);
    return ans;
}
void Readin()
{
    int s,t;
    n = Read();m = Read();
    for (int i=1;i<=n;i++)
        v[i] = Read();
    for (int i=1;i<n;i++)
    {
        s = Read();t = Read();
        Insert(s,t);
    }
}
void Solve()
{
    Dfs1(1);
    Dfs2(1,1);
    for (int i=1;i<=n;i++)
        Add(1,1,n,pos[i],pos[i],v[i]);
    int opt,x,val;
    while (m--)
    {
        opt = Read();x = Read(); if (opt < 3) val = Read();
        if (opt == 1)
            Add(1,1,n,pos[x],pos[x],val);
        if (opt == 2)
            Add(1,1,n,pos[x],mx[x],val);
        if (opt == 3)
            printf("%lld\n",Query(x));
    }
}
int main()
{
    Readin();
    Solve();
    return 0;
}
