#include <cstdio>
#include <algorithm>
const int N = 2000 + 10;
const int M = 10000 + 10;
using namespace std;
int u[M],v[M],w[M];
int n,m;
void Readin()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
        scanf("%d%d%d",u + i,v + i,w + i);
}
int tag[M],fa[M];
int Find(int k)
{
    return fa[k] == k ? k : fa[k] = Find(fa[k]);
}

bool cmp(int a,int b)
{
    return w[a] < w[b];
}
void Work()
{
    for (int i=1;i<=m;++i)
        tag[i] = fa[i] = i;
    sort(tag + 1,tag + m + 1,cmp);
    int x,y,s,t,ans = 0,cnt = 0;
    for (int i=1;i<=m;++i)
    {
        s = u[tag[i]]; t = v[tag[i]];
        x = Find(s); y = Find(t);
        if (x != y)
        {
            fa[x] = y;
            ans = w[tag[i]];
            if (++cnt == n - 1)
                break;
        }
    }
    printf("%d\n",ans);
}
int main()
{
    Readin();
    Work();
    return 0;
}
