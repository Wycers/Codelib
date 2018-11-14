#include <cstdio>
#include <queue>
const int N = 300 + 10;
const int d[4][2] = {-1,0,1,0,0,-1,0,1};
using namespace std;
struct data
{
    int x,y,h;
    inline bool operator < (const data &t) const
    {
        return h > t.h;
    }
};

int n,m,mp[N][N];
void Readin()
{
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            scanf("%d",&mp[i][j]);
}
priority_queue <data> h;
bool vis[N][N];
void Init()
{
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (i == 1 || i == n || j == 1 || j == m)
                h.push((data){i,j,mp[i][j]}),vis[i][j] = true;
}

void Bfs()
{
    int ans = 0;
    data now;
    int x,y,k;
    while (!h.empty())
    {
        now = h.top(), h.pop();
        for (int i=0;i<4;++i)
        {
            x = now.x + d[i][0];
            y = now.y + d[i][1];
            if (x < 1 || x > n || y < 1 || y > m || vis[x][y])
                continue;
            vis[x][y] = true;
            if (mp[x][y] < now.h)
                ans += now.h - mp[x][y], mp[x][y] = now.h;
            h.push((data){x,y,mp[x][y]});
        }
    }
    printf("%d\n",ans);
}
int main()
{
    Readin();
    Init();
    Bfs();
    return 0;
}
