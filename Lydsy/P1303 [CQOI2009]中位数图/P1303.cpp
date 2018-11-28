#include <cstdio>
#include <cstring>
#include <map>
#define N 100005
int num[N],l[2 * N],r[2 * N];
int n,b,pos;

void Readin()
{
	int temp;
	scanf("%d%d",&n,&b);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		if (temp == b)
		{
			num[i] = 0;
			pos = i;
		}
		else 
			num[i] = temp > b ? 1 : -1; 
	}
}

void Work()
{
	l[n] = r[n] = 1;
	int temp = 0;
	for (int i=pos-1;i>=1;i--)
	{
		temp += num[i];
		l[temp + n] ++;
	}
	temp = 0;
	for (int i=pos+1;i<=n;i++)
	{
		temp += num[i];
		r[temp + n] ++;
	}
	int ans = 0;
	for(int i=0;i<=2*n-1;i++)
		ans += l[i] * r[2 * n - i];
	printf("%d\n",ans);
}

int main()
{
	Readin();
	Work();
	return 0;
}
