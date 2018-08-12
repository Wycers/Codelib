#include <cstdio>

int n, m, a[110];
int main()
{
	scanf("%d%d", &n, &m);
	int l, r;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &l, &r);
		for (int j = l; j <= r; ++j)
			a[j] = true;
	}
	int cnt = 0;
	for (int i = 1; i <= m; ++i)
		if (a[i] == false)
			++cnt;
	printf("%d\n", cnt);
	if (cnt == 0)
	{
		puts("");
		return 0;
	}
	for (int i = 1; i <= m; ++i)
		if (a[i] == false)
			printf("%d ", i);
	return 0;
}
