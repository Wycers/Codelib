#include <algorithm>
#include <cstdio>
#include <cmath>
#define N 100005
using namespace std;
int Read()
{
    char ch = getchar();int x = 0;
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48;ch = getchar(); }
    return x;
}
struct tr_
{
    int l,r;
    long long sum;
    bool flag;
} tr[4 * N];
long long a[N];int n;
void Build(int k,int s,int t)
{
    tr[k].l = s;tr[k].r = t;
    if (s == t)
    {
        tr[k].sum = a[s];
        if (tr[k].sum == 1 || tr[k].sum == 0)
            tr[k].flag = true;
        return;
    }
    int mid = (s + t) >> 1;
    Build(k << 1,s,mid);
    Build(k << 1 | 1,mid + 1,t);
    tr[k].sum = tr[k << 1].sum + tr[k << 1 | 1].sum;
    tr[k].flag = tr[k << 1].flag & tr[k << 1 | 1].flag;
}
void Change(int k,int s,int t)
{
    if (tr[k].flag)
        return;
    int l = tr[k].l,r = tr[k].r;
    if (l == r)
    {
        tr[k].sum = (long long)sqrt(tr[k].sum);
        if (tr[k].sum == 1 || tr[k].sum == 0)
            tr[k].flag = true;
        return;
    }
    int mid = (l + r) >> 1;
    if (t <= mid)
        Change(k << 1,s,t);
    else if (mid < s)
        Change(k << 1 | 1,s,t);
    else
    {
        Change(k << 1,s,mid);
        Change(k << 1 | 1,mid + 1,t);
    }
    tr[k].sum = tr[k << 1].sum + tr[k << 1 | 1].sum;
    tr[k].flag = tr[k << 1].flag & tr[k << 1 | 1].flag;
}
long long Query(int k,int s,int t)
{
    int l = tr[k].l,r = tr[k].r;
    if (l == s && r == t)
        return tr[k].sum;
    int mid = (l + r) >> 1;
    if (t <= mid)
        return Query(k << 1,s,t);
    else if (mid < s)
        return Query(k << 1 | 1,s,t);
    else
        return Query(k << 1,s,mid) + Query(k << 1 | 1,mid + 1,t);
}

void Readin()
{
    n = Read();
    for (int i=1;i<=n;i++)
        scanf("%lld",a + i);
}

void Work()
{
    Build(1,1,n);
    int T = Read(),opt,x,y;
    while (T--)
    {
        opt = Read();x = Read();y = Read();
        if (x > y) swap(x,y);
        if (opt)
            printf("%lld\n",Query(1,x,y));
        else
            Change(1,x,y);
    }
}

int main()
{
    Readin();
    Work();
    return 0;
}
