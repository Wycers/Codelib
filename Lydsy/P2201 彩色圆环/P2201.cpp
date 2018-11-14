#include<cstdio>
int n,m;
double ans,p[205],f[205][2];
void Readin()
{
	scanf("%d%d",&n,&m);
}
void Dp()
{
	p[1] = 1;
	for (int i=2;i<=n;i++)
		p[i] = p[i - 1] / m;
	f[0][1] = 1;
	for (int i=0;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			f[j][0] += (j - i) * p[j - i] * (f[i][0] * (m - 2) / m + f[i][1] * (m - 1) / m);
			f[j][1] += (j - i) * p[j - i] * f[i][0] / m;
		}
	ans = p[n] * n;
	for(int i=1;i<n;i++)
		ans += i * i * f[n - i][0] * p[i];
}
int main()
{
	Readin();
	Dp();
	printf("%.5lf",ans);
	return 0;
}
