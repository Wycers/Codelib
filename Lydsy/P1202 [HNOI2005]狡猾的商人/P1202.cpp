#include <cstdio>
#include <cstring>
#define N 1005
using namespace std;
int n,m;
int fa[N],s[N];
int Find(int x)
{
    if (fa[x] == x)
        return x;
    int fx = fa[x];
    fa[x] = Find(fa[x]);
    s[x] += s[fx];
    return fa[x];
}

void Work()
{
    scanf("%d%d",&n,&m);

    bool flag = true;
    int u,v,w;
    memset(s,0,sizeof(s));
    for (int i=0;i<=n+1;i++)
        fa[i] = i;

    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w); u--;
        int x = Find(u),y = Find(v);
        if (x != y)
        {
            fa[x] = y;
            s[x] = s[v] - s[u] + w;
        }
        else if (s[u] - s[v] != w)
            flag = false;
    }
    printf(flag ? "true\n" : "false\n");
}

int main()
{
    int T;
    for (scanf("%d",&T);T;T--)
        Work();
    return 0;
}
