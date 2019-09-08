#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N], b[N], c[N], tag[N];

bool cmp(const int &x, const int &y)
{
	return c[x] > c[y];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", a + i, b + i);
	long long suma = 0, sumb = 0;
	for (int i = 1; i <= n; ++i)
		suma += (long long)a[i];
	for (int i = 1; i <= n; ++i)
		sumb += (long long)b[i];
	if (sumb > m)
	{
		puts("-1");
		return 0;
	}
	if (suma <= m)
	{
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		c[i] = a[i] - b[i];
	for (int i = 1; i <= n; ++i)
		tag[i] = i;
	sort(tag + 1, tag + n + 1, cmp);
	for (int i = 1; i <= n; ++i)
		if ((suma = suma - c[tag[i]]) <= m)
		{
			printf("%d\n", i);
			return 0;
		}
	return 0;
}
