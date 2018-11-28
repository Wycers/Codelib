#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 2000000 + 10;
using namespace std;
int Read()
{
    int x = 0;char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x;
}
vector<int> a[N];
int n,m,c[N],ans = 0;
void Readin()
{
    n = Read(); m = Read();
    int p,q;
    for (int i=0;i<n;i++)
        c[i] = Read();
    for (int i=0;i<n;i++)
    {
        p = Read();
        while (p--)
        {
            q = Read();
            a[i].push_back(q);
        }
    }
}

bool cmp(int a,int b)
{
    return c[a] < c[b];
}
void Dfs(int x)
{
    int nn = a[x].size(),t;
    for (int i=0;i<nn;i++)
        Dfs(a[x][i]);
    sort(a[x].begin(),a[x].end(),cmp);
    c[x] += nn;
    for(int i=0;i<nn;i++)
	{
		t = c[a[x][i]];
		if(c[x] + t - 1 <= m)
		{
			c[x] += t-1;
			++ans;
		}
		else break;
	}
}

int main()
{
    Readin();
    Dfs(0);
    printf("%d\n",ans);
    return 0;
}
