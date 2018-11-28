#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
const int Inf = 0x3f3f3f3f;
const int N = 305;
const short d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
using namespace std;
int mp[N][N],n;
bool mark[N][N];
struct data
{
    int x,y,t;
};
void Init()
{
    int x,y,t,dx,dy;
    for (int i=0;i<=305;i++)
        for (int j=0;j<=305;j++)
            mp[i][j] = Inf;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&x,&y,&t);
        mp[x][y] = min(mp[x][y],t);
        for (int i=0;i<4;i++)
        {
            dx = x + d[i][0];dy = y + d[i][1];
            if (dx < 0 || dy < 0)
                continue;
            mp[dx][dy] = min(mp[dx][dy],t);
        }
    }
}
queue<data> q;
void Bfs()
{
    data now;int x,y,time,nx,ny;
    now.x = 0;now.y = 0;now.t = 0;
    q.push(now);
    memset(mark,false,sizeof(mark));
	mark[0][0] = true;
	if(mp[0][0] == Inf)
    {
        printf("0");
        return;
    }
	while(!q.empty())
	{
        now = q.front();q.pop();
	    x = now.x;y = now.y;time = now.t;
		for(int i=0;i<4;i++)
		{
			nx = x + d[i][0];
			ny = y + d[i][1];
			if (mark[nx][ny] || nx < 0 || ny < 0 || time + 1 >= mp[nx][ny])
                continue;
            if (mp[nx][ny] == Inf)
            {
                printf("%d\n",time + 1);
                return;
            }
            now.x = nx;now.y = ny;now.t = time + 1;
			q.push(now);
			mark[nx][ny] = true;
		}
	}
	printf("-1");

}
int main()
{
    Init();
    Bfs();
    return 0;
}
