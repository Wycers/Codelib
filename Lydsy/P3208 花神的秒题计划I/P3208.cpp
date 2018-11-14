#include <cstdio>
#include <cstring>
#include <algorithm> 
#define N 705
using namespace std;
const short d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int map[N][N],f[N][N],n;
bool per[N][N];

void Readin()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&map[i][j]);
	memset(per,false,sizeof(per));
}

int Find(int x,int y)  
{  
    if(f[x][y])return f[x][y];  
    for(int i=0;i<4;i++)  
    {  
        int dx = x + d[i][0],dy = y + d[i][1];  
        if(per[dx][dy] || map[dx][dy] >= map[x][y])
			continue;
        f[x][y] = max(f[x][y],Find(dx,dy));  
    }  
    return ++f[x][y];  
}  

void Solve()
{
	int m,x,y,a,b,t;
	char opt[5];
	for (scanf("%d",&m);m--;)
	{
		scanf("%s",opt);
		if (opt[0] == 'C')
		{
			scanf("%d%d%d",&x,&y,&t);
			map[x][y] = t;
		} else
		if (opt[0] == 'S')
		{
			scanf("%d%d%d%d",&x,&y,&a,&b);
			for (int i=x;i<=a;i++)
				for (int j=y;j<=b;j++)
					per[i][j] = true;
		} else
		if (opt[0] == 'B')
		{
			scanf("%d%d%d%d",&x,&y,&a,&b);
			for (int i=x;i<=a;i++)
				for (int j=y;j<=b;j++)
					per[i][j] = false;
		} else
		if (opt[0] == 'Q')  
        {  
            memset(f,0,sizeof(f));  
            int ans = 0;
            for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)  
                	if(!per[i][j])
						ans=max(ans,Find(i,j));  
            printf("%d\n",ans - 1);  
        }  
	}
}

int main()
{
	freopen("input.in","r",stdin);
	Readin();
	Solve();
	return 0;
}
