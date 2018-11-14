













#include<cstdio>
#include<iostream>
using namespace std;
int n,m,a[51],ans;




bool Judge(int x)
{
	int t = min(m, x);
	for (int i = 1; i <= n; i++)
		if(a[i] < x)
		{
			t -= (x - a[i]);
			if (t < 0)
				return 0;
		}
	return 1;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l = 1,r = 1000000000;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(Judge(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else 
			r = mid - 1;
	}
	printf("%d",ans);
	return 0;
}
