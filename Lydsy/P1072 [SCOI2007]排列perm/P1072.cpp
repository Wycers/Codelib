#include <cstdio>
#include <cstring>
using namespace std;
int a[15],pow[15],v[15],cnt[15],f[1025][1025];
char ch[15];int len,d,T;
void Dp()
{
	for (int i=0;i<=pow[len];i++)
		for (int j=0;j<=d;j++)
			f[i][j]=0;
	f[0][0]=1;
	for (int i=0;i<pow[len];i++)
		for (int j=0;j<d;j++)
			if (f[i][j])
				for (int k=1;k<=len;k++)
					if ((i&pow[k-1])==0)
						f[i|pow[k-1]][(a[k]+j*10)%d]+=f[i][j];
}
int main()
{
	pow[0]=1;for (int i=1;i<=15;i++) pow[i]=pow[i-1]*2;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",ch+1);scanf("%d",&d);
		len=strlen(ch+1);
		for (int i=0;i<=9;i++) v[i]=1,cnt[i]=0;
		for (int i=1;i<=len;i++)
		{
			a[i]=ch[i]-'0';
			cnt[a[i]]++;
			v[a[i]]*=cnt[a[i]];
		}
		Dp();
		for(int i=0;i<=9;i++) f[pow[len]-1][0]/=v[i];
		printf("%d\n",f[pow[len]-1][0]);
	}
	return 0;
} 
