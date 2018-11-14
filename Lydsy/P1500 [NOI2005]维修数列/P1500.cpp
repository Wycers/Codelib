#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>
#define size sz
const int N = 1e6 + 10;
const int Inf = 0x3f3f3f3f;
using namespace std;
int Read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
int n,m,a[N];
int id[N],fa[N],c[N][2];
int sum[N],sz[N],v[N],mx[N],lx[N],rx[N],rt,cnt;
bool tag[N],rev[N];
queue<int> q;
void Update(int x)
{
    int l = c[x][0],r = c[x][1];
    sum[x] = sum[l] + sum[r] + v[x];
    sz[x] = sz[l] + sz[r] + 1;
    mx[x] = max(mx[l],mx[r]);
    mx[x] = max(mx[x],rx[l] + v[x] + lx[r]);
    lx[x] = max(lx[l],sum[l] + v[x] + lx[r]);
    rx[x] = max(rx[r],sum[r] + v[x] + rx[l]);
}
void Pushdown(int x)
{
    int l = c[x][0],r = c[x][1];
    if (tag[x])
    {
        rev[x] = tag[x] = false;
        if (l) tag[l] = true,v[l] = v[x],sum[l] = v[x] * sz[l];
        if (r) tag[r] = true,v[r] = v[x],sum[r] = v[x] * sz[r];
        if (v[x] >= 0)
        {
            if (l) lx[l] = rx[l] = mx[l] = sum[l];
            if (r) lx[r] = rx[r] = mx[r] = sum[r];
        }
        else
        {
            if (l) lx[l] = rx[l] = 0,mx[l] = v[x];
            if (r) lx[r] = rx[r] = 0,mx[r] = v[x];
        }

    }
    if (rev[x])
    {
        rev[x] ^= 1; rev[l] ^= 1; rev[r] ^= 1;
        swap(lx[l],rx[l]); swap(lx[r],rx[r]);
        swap(c[l][0],c[l][1]); swap(c[r][0],c[r][1]);
    }
}
int Find(int x,int rk)
{
    Pushdown(x);
    int l = c[x][0],r = c[x][1];
    if (sz[l] + 1 == rk)
        return x;
    if (sz[l] >= rk)
        return Find(l,rk);
    return Find(r,rk - sz[l] - 1);
}
void Rec(int x)
{
    if (!x)
        return;
    int l = c[x][0],r = c[x][1];
    Rec(l); Rec(r); q.push(x);
    fa[x] = c[x][0] = c[x][1] = 0;
    tag[x] = rev[x] = false;
}
void Build(int l,int r,int f)
{
    if (l > r) return;
    int mid = (l + r) >> 1,now = id[mid],last = id[f];
    if (l == r)
    {
        sum[now] = a[l]; sz[now] = 1;
        tag[now] = rev[now] = false;
        if (a[l] >= 0)
            lx[now] = rx[now] = mx[now] = a[l];
        else
            lx[now] = rx[now] = 0,mx[now] = a[l];
    }
    else
        Build(l,mid - 1,mid),Build(mid + 1,r,mid);
    v[now] = a[mid]; fa[now] = last; Update(now);
    if(last)c[last][mid >= f] = now;
}
void Rotate(int x,int &k)
{
    int y = fa[x],z = fa[y],l,r;
    l = (c[y][1] == x); r = l ^ 1;
    if (y == k)
        k = x;
    else
        c[z][c[z][1] == y] = x;
    fa[c[x][r]] = y;fa[y] = x;fa[x] = z;
    c[y][l] = c[x][r]; c[x][r] = y;
    Update(y); Update(x);
}
void Splay(int x,int &k)
{
    int y,z;
    while (x != k)
    {
        y = fa[x],z = fa[y];
        if (y != k)
        {
            if ((c[y][0] == x) ^ (c[z][0] == y))
                Rotate(x,k);
            else
                Rotate(y,k);
        }
        Rotate(x,k);
    }
}
int split(int k,int tot)
{
    int x = Find(rt,k),y = Find(rt,k + tot + 1);
    Splay(x,rt); Splay(y,c[x][1]);
    return c[y][0];
}
void Query(int k,int tot)
{
    int x = split(k,tot);
    printf("%d\n",sum[x]);
}
void modify(int k,int tot,int val)
{
    int x = split(k,tot),y = fa[x];
    v[x] = val; tag[x] = true; sum[x] = sz[x] * val;
    if (val >= 0) lx[x] = rx[x] = mx[x] = sum[x];
    else lx[x] = rx[x] = 0,mx[x] = val;
    Update(y); Update(fa[y]);
}
void Rever(int k,int tot)
{
    int x = split(k,tot),y = fa[x];
    if (!tag[x])
    {
        rev[x] ^= 1;
        swap(c[x][0],c[x][1]);
        swap(lx[x],rx[x]);
        Update(y); Update(fa[y]);
    }
}
void Erase(int k,int tot)
{
    int x = split(k,tot),y = fa[x];
    Rec(x); c[y][0] = 0;
    Update(y); Update(fa[y]);
}
void Insert(int k,int tot)
{
    for (int i=1;i<=tot;++i)
        a[i] = Read();
    for (int i=1;i<=tot;++i)
        if (!q.empty()) id[i] = q.front(),q.pop();
        else id[i] = ++cnt;
    Build(1,tot,0); int z = id[(1 + tot) >> 1];
    int x = Find(rt,k + 1),y = Find(rt,k + 2);
    Splay(x,rt); Splay(y,c[x][1]);
    fa[z] = y; c[y][0] = z;
    Update(y); Update(x);
}
void Readin()
{
    n = Read();m = Read();
    mx[0] = a[1] = a[n + 2] = -Inf;
    for (int i=1;i<=n;++i)
        a[i + 1] = Read();
}
void Solve()
{
    for (int i=1;i<=n+2;++i)
        id[i] = i;
    Build(1,n + 2,0);
    rt = (n + 3) >> 1;cnt = n + 2;
    int k,tot,val;
    char ch[10];
    while (m--)
    {
        scanf("%s",ch);
        if (ch[0] != 'M' || ch[2] != 'X')
            k = Read(), tot = Read();
        if (ch[0] == 'I')
            Insert(k,tot);
        if (ch[0] == 'D')
            Erase(k,tot);
        if (ch[0] == 'M')
        {
            if (ch[2] == 'X')
                printf("%d\n",mx[rt]);
            else
                val = Read(),modify(k,tot,val);
        }
        if (ch[0] == 'R')
            Rever(k,tot);
        if (ch[0] == 'G')
            Query(k,tot);
    }
}
int main()
{
    Readin();
    Solve();
    return 0;
}
