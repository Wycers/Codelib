#include <cstdio>
#include <cstring>
#define mo 1000000001
int n;
int pow[20],m[20],f[20][2048],num[20][15];
bool b[300005];
void Pre_work()
{
	pow[0]=1;
	memset(b,true,sizeof(b));
	for (int i=1;i<=20;i++) pow[i]=pow[i-1]*2;
}
int Dp(int k)
{
	memset(m,0,sizeof(m));
	num[1][1]=k;
	for(int i=1;i<=18;i++)
	{
		if (i!=1) 
		{
			if (num[i-1][1]*2>n) num[i][1]=n+1;
			else num[i][1]=num[i-1][1]*2;
		}
		for (int j=2;j<=11;j++)
			if (num[i][j-1]*3>=n) num[i][j]=n+1;
				else num[i][j]=num[i][j-1]*3;
	}
	
	for (int i=1;i<=18;i++) 
		for (int j=1;j<=11;j++)
			if (num[i][j]<=n)
			{
				m[i]+=pow[j-1];
				b[num[i][j]]=false;
			}
			
	for(int i=0;i<=18;i++)
		for(int x=0;x<=m[i];x++)
			f[i][x]=0;
	f[0][0]=1;
	for(int i=0;i<18;i++)
		for(int x=0;x<=m[i];x++)
		{
			if(f[i][x])
				for(int y=0;y<=m[i+1];y++)
					if(((x&y)==0)&&((y&(y>>1))==0))
						f[i+1][y]=(f[i][x]+f[i+1][y])%mo;
		}
	return f[18][0];
}
int main()
{
	scanf("%d",&n);
	long long ans=1;
	Pre_work();
	for (int i=1;i<=n;i++) if (b[i]) ans=(ans*Dp(i))%mo;
	printf("%d\n",ans);
	return 0;
}
