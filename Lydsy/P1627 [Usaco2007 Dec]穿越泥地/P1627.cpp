#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
const int N = 500;
const int M = 1000;
const int d[4][2] = {-1,0,1,0,0,1,0,-1};
using namespace std;
bool mp[M + 10][M + 10];
int ex,ey;
void Readin()
{
    int t,x,y;
    scanf("%d%d%d",&ex,&ey,&t);
    while (t--)
    {
        scanf("%d%d",&x,&y);
        mp[x + N][y + N] = true;
    }
}
queue<pair<int,int> > q;
int f[M + 10][M + 10];
void Bfs()
{
    pair<int,int> now;
    int x,y,dx,dy;
    memset(f,0x3f,sizeof(f));
    q.push(make_pair(N,N));
    f[N][N] = 0;
    while (!q.empty())
    {
        now = q.front(); q.pop();
        x = now.first;y = now.second;
        for (int i=0;i<4;++i)
        {
            dx = x + d[i][0];dy = y + d[i][1];
            if (dx < 0 || dx > M || dy < 0 || dy > M || mp[dx][dy])
                continue;
            if (f[dx][dy] <= f[x][y] + 1)
                continue;
            f[dx][dy] = f[x][y] + 1;
            if (dx == ex + N && dy == ey + N)
                break;
            q.push(make_pair(dx,dy));
        }
    }
    printf("%d\n",f[ex + N][ey + N]);
}

int main()
{
    Readin();
    Bfs();
    return 0;
}
