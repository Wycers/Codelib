#include <cstdio>
#include <algorithm>
using namespace std;
int n; char ch1[100], ch2[100];
int ans[10005], k = 0;
int main()
{
	scanf("%d", &n);
	scanf("%s", ch2);
	scanf("%s", ch1);
	for (int i = 0; i < n; ++i)
	{
		if (ch1[i] == ch2[i])
			continue;
		int tag = -1;
		for (int j = i + 1; j < n; ++j)
			if (ch2[j] == ch1[i])
			{
				tag = j;
				break;
			}
		if (tag == -1)
		{
			puts("-1");
			return 0;
		}
		char tmp = ch2[tag];
		for (int j = tag - 1; j >= i; --j)
		{
			swap(ch2[j + 1], ch2[j]);
			ans[++k] = j + 1;
			if (k > 10000)
			{
				puts("-1");
				return 0;
			}
		}
		ch2[i] = tmp;
	}
	printf("%d\n", k);
	for (int i = 1; i <= k; ++i)
		printf("%d ", ans[i]);
}
