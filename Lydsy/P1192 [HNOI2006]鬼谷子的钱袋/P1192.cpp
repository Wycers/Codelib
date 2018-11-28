#include <cstdio>
int main()
{
	int n,s = 1,k = 0;
	scanf("%d",&n);
	while (s <= n)
		s <<= 1, k++;
	printf("%d\n",k);
	return 0;
}
		
	
