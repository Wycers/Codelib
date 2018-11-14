#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 55;
const int M = 1e5 + 10;
using namespace std;
struct edge
{
    int to,next;
} e[M];
int head[N * N],cnt = 0;
char mp[N][N];
int n,m,mn;
void Readin()
{
    scanf("%d%d",&n,&m);getchar();
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
            mp[i][j] = getchar();
        getchar();
    }
}

void Insert(int u,int v)
{
    e[++cnt] = (edge){v,head[u]};
    head[u] = cnt;
}
void Init()
{
    int a[N][N],b[N][N];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int tx = 0,ty = 0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (mp[i][j] == '*')
            {
                a[i][j] = (j > 1 && mp[i][j - 1] == '*') ? a[i][j - 1] : ++tx;
                b[i][j] = (i > 1 && mp[i - 1][j] == '*') ? b[i - 1][j] : ++ty;
            }
    mn = max(tx,ty);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (mp[i][j] == '*')
                Insert(a[i][j],b[i][j]);
}
int from[N * N];bool vis[N * N];
bool Match(int k)
{
    int v;
    for (int i=head[k];i;i=e[i].next)
    {
        v = e[i].to;
        if (!vis[v])
        {
            vis[v] = true;
            if (from[v] == -1 || Match(from[v]))
            {
                from[v] = k;
                return true;
            }
        }
    }
    return false;
}
int Hungary()
{
	int ans = 0;
	memset(from,255,sizeof(from));
	for (int i=1;i<=mn;i++)
	{
		memset(vis,false,sizeof(vis));
		if (Match(i))
            ++ans;
	}
	return ans;
}
int main()
{
    Readin();
    Init();
    printf("%d\n",Hungary());
    return 0;
}
