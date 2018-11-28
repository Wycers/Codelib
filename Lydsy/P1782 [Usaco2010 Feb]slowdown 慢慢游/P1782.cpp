#include <cstdio>
const int N = 1e5 + 10;
const int M = 2e5 + 10;
using namespace std;
int Read()
{
    int x = 0;char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x;
}
struct edge
{
    int to,next;
} e[M];
int head[N],cnt = 0;
void Insert(int u,int v)
{
    e[++cnt] = (edge){v,head[u]}; head[u] = cnt;
    e[++cnt] = (edge){u,head[v]}; head[v] = cnt;
}

int n,p[N];
void Readin()
{
    n = Read();
    for (int i=1;i<n;++i)
        Insert(Read(),Read());
    for (int i=1;i<=n;++i)
        p[Read()] = i;
}

int ans[N],t[N];
int lowbit(int x)
{
    return x & -x;
}
void Change(int pos,int x)
{
    for (int i=pos;i<=n;i+=lowbit(i))
        t[i] += x;
}
int Query(int x)
{
    int sum = 0;
    for (int i=x;i>0;i-=lowbit(i))
        sum += t[i];
    return sum;
}
void Dfs(int u,int f)
{
    int v;
    ans[p[u]] = Query(p[u]);
    Change(p[u],1);
    for (int i=head[u];i;i=e[i].next)
    {
        v = e[i].to;
        if (v != f)
            Dfs(v,u);
    }
    Change(p[u],-1);
}

int main()
{
    Readin();
    Dfs(1,0);
    for (int i=1;i<=n;++i)
        printf("%d\n",ans[i]);
    return 0;
}
