#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 50000 + 10;
using namespace std;
int h[N],v[N],n;
void Readin()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d%d",h + i,v + i);
}
int st[N],top = 0,ans[N];
void Work()
{
    int now = 0,mx = 0;
    while (now++ <= n)
    {
        while (top && h[now] > h[st[top]])
            ans[now] += v[st[top--]];
        mx = max(mx,ans[now]);
        st[++top] = now;
    }
    top=now=0;now=n+1;
    memset(st,0,sizeof(st));
    while (now-- >= 1)
    {
        while (top && h[now] > h[st[top]])
            ans[now] += v[st[top--]];
        mx = max(mx,ans[now]);
        st[++top] = now;
    }
    printf("%d",mx);
}
int main()
{
    Readin();
    Work();
    return 0;
}
