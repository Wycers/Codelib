#include <cstdio>
#include <algorithm>
const int N = 50000 + 10;
using namespace std;
int Disc[2 * N],cnt;
void Disc_Init()
{
    sort(Disc + 1,Disc + cnt + 1);
    cnt = unique(Disc + 1,Disc + cnt + 1) - Disc - 1;
}
int Disc_Find(int x)
{
    int l = 1,r = cnt,mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (Disc[mid] == x)
            return mid;
        if (x < Disc[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
}
int s[N],t[N];
int n;
void Readin()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d%d",s + i,t + i);
        Disc[++cnt] = s[i];
        Disc[++cnt] = t[i];
    }
}
int tag[8 * N],mx[8 * N];
void Pushdown(int k,int l,int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    long long t = tag[k];tag[k] = 0;
    tag[k << 1] += t;tag[k << 1 | 1] += t;
    mx[k << 1] += t; mx[k << 1 | 1] += t;
}
void Update(int k,int l,int r,int x,int y)
{
    if (tag[k]) Pushdown(k,l,r);
    if (l == x && r == y)
    {
        ++tag[k];
        ++mx[k];
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) Update(k << 1,l,mid,x,min(mid,y));
    if (mid < y) Update(k << 1 | 1,mid + 1,r,max(mid + 1,x),y);
    mx[k] = max(mx[k << 1],mx[k << 1 | 1]);
}
void Work()
{
    int x,y;
    for (int i=1;i<=n;++i)
    {
        x = Disc_Find(s[i]);
        y = Disc_Find(t[i]);
        Update(1,1,cnt,x,y);
    }
    Pushdown(1,1,cnt);
    printf("%d\n",mx[1]);
}
int main()
{
    Readin();
    Disc_Init();
    Work();
    return 0;
}
