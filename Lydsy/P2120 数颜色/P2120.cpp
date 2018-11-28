#include <cstdio>
#include <algorithm>
#include <cmath>
#define N 10001
#define M 1000001
using namespace std;
int n,q,a[N];
int m,block,pos[N],pre[N],b[N],last[M];
void Readin()
{
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
}

void Reset(int k)
{
    int l = (k - 1) * block + 1;
    int r = min(k * block,n);
    for (int i=l;i<=r;i++)
        pre[i] = b[i];
    sort(pre + l,pre + r + 1);
}

void Build()
{
    for (int i=1;i<=n;i++)
    {
        b[i] = last[a[i]];
        last[a[i]] = i;
        pos[i] = (i - 1) / block + 1;
    }
    for (int i=1;i<=m;i++)
        Reset(i);
}

void Pre_work()
{
    block = int(sqrt(n) + log(2 * n) / log(2));
    m = n / block;
    if (n % block)
        m ++;
    Build();
}

int Find(int k,int v)
{
    int l = (k - 1) * block + 1;
    int r = min(k * block,n);
    int temp = l;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (pre[mid] < v)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l - temp;
}

int Query(int l,int r)
{
    int ans = 0;
    if (pos[l] == pos[r])
    {
        for (int i=l;i<=r;i++)
        if (b[i] < l)
            ans++;
    }
    else
    {
        for (int i=l;i<=block * pos[l];i++)
            if (b[i] < l)
                ans ++;
        for (int i=block * (pos[r] - 1) + 1;i<=r;i++)
            if (b[i] < l)
                ans ++;
    }
    for (int i=pos[l] + 1;i < pos[r];i++)
        ans += Find(i,l);
    return ans;
}

void Change(int k,int v)
{
    for (int i=1;i<=n;i++)
        last[a[i]] = 0;
    a[k] = v;
    for (int i=1;i<=n;i++)
    {
        int t = b[i];
        b[i] = last[a[i]];
        if (t != b[i])
            Reset(pos[i]);
        last[a[i]] = i;
    }
}

int main()
{
    Readin();
    Pre_work();
    char ch[5];int x,y;
    while (q --)
    {
        scanf("%s%d%d",ch,&x,&y);
        if (ch[0] == 'Q')
            printf("%d\n",Query(x,y));
        else
            Change(x,y);
    }
    return 0;
}
