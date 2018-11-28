#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
const int N = 50 + 10;
const int Inf = 0x3f3f3f3f;
const int dx[8] = {-1,-1,-1, 0,0,1 ,1,1};
const int dy[8] = {-1, 0, 1,-1,1,-1,0,1};
using namespace std;
int n,m,tx,ty,sx,sy,ans;
bool mp[N][N];
bool mark[N][N];
struct data
{
    int x,y,t;
};
void Readin()
{
    scanf("%d%d",&n,&m); char ch = getchar();
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            ch = getchar();
            mp[i][j] = false;
            if (ch == 'X')
            {
                mp[i][j] = true;
                tx = i;ty = j;
            }
            if (ch == '*')
                sx = i,sy = j;
        }
        getchar();
    }
}
void Prework()
{
    memset(mark,false,sizeof(mark));
    for (int i=0;i<=n;++i)
        if (tx + i > n)
            break;
        else
            mark[tx + i][ty] = true;
}
queue<data> q;
int f[2][N][N];
void Bfs()
{
    q.push((data){sx,sy,0});
    memset(f,0,sizeof(f));
    int x,y,t,tag,nx,ny;
    while (!q.empty())
    {
        x = q.front().x; y = q.front().y; t = q.front().t; q.pop();
        for (int i=0;i<8;++i)
        {
            nx = x + dx[i]; ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny])
                continue;
            if((mark[x][y] || mark[nx][ny]) && ny <= y)
                continue;
            if(mark[nx][ny] && !f[1][nx][ny])
            {
                f[1][nx][ny] = f[t][x][y] + 1;
                q.push((data){nx,ny,1});
            }
            else if(!f[t][nx][ny])
            {
                f[t][nx][ny] = f[t][x][y] + 1;
                q.push((data){nx,ny,t});
            }
        }
    }
}
int main()
{
    Readin();
    Prework();
    Bfs();
    printf("%d\n",f[1][sx][sy]);
    return 0;
}
