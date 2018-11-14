#include<cstdio>
#define N 10010
#define inf 100000000
int mn[N];
int a[N],n;
void Readin()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a + i);
}
inline int Find(int x,int l,int r)
{
	int s = 0,mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (mn[mid] < x)
        {
            s = mid;
            l = mid + 1;
        }
		else
            r = mid - 1;
	}
	return s;
}
void Dp()
{
    int ans = 1;
    for (int i=1;i<=n;i++)
        mn[i] = inf;
	mn[1] = a[1];
	for (int i=2;i<=n;i++)
	  {
	  	int f = Find(a[i],1,ans);
	  	if (f == ans)
            mn[++ans] = a[i];
	  	else if (a[i] < mn[f+1])
            mn[f + 1] = a[i];
	  }
	printf("%d",ans);
}
int main()
{
    Readin();
    Dp();
    return 0;
}
