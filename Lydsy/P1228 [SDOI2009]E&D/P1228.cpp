#include <cstdio>
long long power[34];
int SG(int a,int b)
{
	int sg;
	a--;b--;
	sg=0;
	while (a%power[sg+1]>=power[sg]||b%power[sg+1]>=power[sg]) sg++;
	return sg;
}
int main()
{
	power[0]=1;
	for (int i=1;i<=33;i++) power[i]=power[i-1]*2;
	int ans;
	int t,n,a,b;
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		ans=0;
		for (int j=1;j<=n/2;j++)
		{
			scanf("%d%d",&a,&b);
			ans^=SG(a,b);
		}
		if (ans) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}
