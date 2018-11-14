#include <cstdio>
using namespace std;
int st[50005],top = 0;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	int now,ans = n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&now);
		scanf("%d",&now);
		while (st[top] > now)
			top --;
		if (st[top] == now)
			ans--;
		else
			st[++top] = now;
	}
	printf("%d\n",ans);
	return 0;
}
	
