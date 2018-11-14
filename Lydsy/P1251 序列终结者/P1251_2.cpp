#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
const int N = 2e5 + 10;
const int Inf = 0x3f3f3f3f;
using namespace std;
int Read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch){if (ch == '-') f = -1;ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
int n,m;
int a[N],fa[N],c[N][2],sz[N],id[N],mx[N],v[N],tag[N],root;
bool rev[N];
void Update(int k)
{
    int l = c[k][0],r = c[k][1];
    sz[k] = sz[l] + sz[r] + 1;
    mx[k] = max(mx[l],mx[r]);
    mx[k] = max(mx[k],v[k]);
}
void Pushdown(int k)
{
    int l = c[k][0],r = c[k][1],t = tag[k];
    if (t)
    {
        if (l) { tag[l] += t; v[l] += t; mx[l] += t;}
        if (r) { tag[r] += t; v[r] += t; mx[r] += t;}
        tag[k] = 0;
    }
    if (rev[k])
    {
        rev[k] = false;
        rev[l] ^= 1; rev[r] ^= 1;
        swap(c[k][0],c[k][1]);
    }
}
void Build(int l,int r,int f)
{
    if (l > r)
        return;
    int mid = (l + r) >> 1,now = id[mid],last = id[f];
    if (l == r)
    {
        fa[now] = last;
        c[last][mid >= f] = now;
        sz[now] = 1;
        v[now] = mx[now] = 0;
        return;
    }
    else
        Build(l,mid - 1,mid),Build(mid + 1,r,mid);
    v[now] = 0; fa[now] = last; Update(now);
    if (last) c[last][mid >= f] = now;
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
int Find(int k,int rk)
{
    Pushdown(k);
    int l = c[k][0],r = c[k][1];
    if (sz[l] + 1 == rk)
        return k;
    if (sz[l] >= rk)
        return Find(l,rk);
    return Find(r,rk - sz[l] - 1);
}
int Split(int l,int r)
{
    int x = Find(root,l),y = Find(root,r + 2);
    Splay(x,root); Splay(y,c[x][1]);
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
int main()
{
    n = Read();m = Read();
    for (int i=1;i<=n + 2;++i) id[i] = i;
    mx[0] = -Inf;
    Build(1,n + 2,0); root = (n + 3) >> 1;
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
        else
            Query(l,r);
    }
    return 0;
}
