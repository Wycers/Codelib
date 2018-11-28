#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#define N 35
using namespace std;
const int d[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
bool mp[N][N];
int n,m,k;

void Readin()
{
    scanf("%d%d%d",&n,&m,&k);
    getchar();
    memset(mp,false,sizeof(mp));
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            if (getchar() == '1')
                mp[i][j] = true;
        getchar();
    }
}

int Dis[N][N];
double ans = 0;
bool inq[N][N];
double Getdis(int a,int b)
{
    return sqrt(a * a + b * b);
}
void Putans(int x,int y)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (Dis[i][j] <= k && ans < Getdis((i - x),(j - y)))
                ans = Getdis((i - x),(j - y));
}
queue<pair<int,int> > q;
void Try(int x,int y)
{
    memset(Dis,0x3f,sizeof(Dis));
    memset(inq,false,sizeof(inq));
    q.push(make_pair(x,y));
    inq[x][y] = true;
    Dis[x][y] = (int)mp[x][y];
    while (!q.empty())
    {
        pair<int,int> now = q.front(); q.pop();
        int nx = now.first,ny = now.second;
        for (int i=0;i<4;i++)
        {
            int dx = now.first + d[i][0],dy = now.second + d[i][1];
            if (dx < 1 || dx > n || dy < 1 || dy > m )
                continue;
            if (Dis[nx][ny] + (int)mp[dx][dy] < Dis[dx][dy])
            {
                Dis[dx][dy] = Dis[nx][ny] + (int)mp[dx][dy];
                if (!inq[dx][dy])
                    q.push(make_pair(dx,dy));
                inq[dx][dy] = true;
            }
            inq[nx][ny] = false;
        }
    }
    Putans(x,y);
}

void Work()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            Try(i,j);
    printf("%.6lf\n",ans);
}
int main()
{
    Readin();
    Work();
    return 0;
}
