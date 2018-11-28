#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
const int N = 2e5 + 10;
const int Inf = 0x3f3f3f3f;
using namespace std;
int Read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar(); };
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
int c[N][2],fa[N],mx[N],sz[N],id[N],tag[N],v[N],a[N],n,m,rt;
bool rev[N];
void Readin()
{
    n = Read(); m = Read();
    for (int i=1;i<=n+2;++i)
        a[i] = 0;
}
void Update(int k)
{
    int l = c[k][0],r = c[k][1];
    mx[k] = max(mx[l],mx[r]);
    mx[k] = max(mx[k],v[k]);
    sz[k] = sz[l] + sz[r] + 1;
}
void Pushdown(int k)
{
    int l = c[k][0],r = c[k][1],t = tag[k];
    if (t)
    {
        tag[k] = 0;
        if (l) {tag[l] += t; mx[l] += t; v[l] += t;}
        if (r) {tag[r] += t; mx[r] += t; v[r] += t;}
    }
    if (rev[k])
    {
        rev[k] = 0;
        rev[l] ^= 1;rev[r] ^= 1;
        swap(c[k][0],c[k][1]);
    }
}
void Build(int l,int r,int f)
{
    if (l > r)
        return;
    int mid = (l + r) >> 1,now = id[l],last = id[f];
    if (l == r)
    {
        fa[now] = last;
        sz[now] = 1;
        mx[now] = a[l];
        c[last][mid >= f] = now;
        return;
    }
    else
        Build(l,mid - 1,mid),Build(mid + 1,r,mid);
    now = id[mid];
    v[now] = a[mid];
    fa[now] = last;
    Update(now);
    c[last][mid >= f] = now;
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
int Split(int l,int r)
{
    int x = Find(rt,l),y = Find(rt,r + 2);
    Splay(x,rt); Splay(y,c[x][1]);
    return c[y][0];
}
void Rever(int l,int r)
{
    int x = Split(l,r);
    rev[x] ^= 1;
}
void Query(int l,int r)
{
    int x = Split(l,r);
    printf("%d\n",mx[x]);
}
void Modify(int l,int r,int val)
{
    int x = Split(l,r);
    tag[x] += val; v[x] += val; mx[x] += val;
}
void Solve()
{
    mx[0] = -Inf;
    for (int i=1;i<=n+2;++i)
        id[i] = i;
    Build(1,n+2,0);rt = (n + 3) >> 1;
    int opt,l,r,val;
    while (m--)
    {
        opt = Read(); l = Read(); r = Read();
        if (opt == 1)
        {
            val = Read();
            Modify(l,r,val);
        }
        else if (opt == 2)
            Rever(l,r);
        else if (opt == 3)
            Query(l,r);
    }
}
int main()
{
    Readin();
    Solve();
    return 0;
}
