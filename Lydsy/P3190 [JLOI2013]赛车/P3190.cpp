#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define eps 1e-8
using namespace std;
const int N = 1e4 + 10;
struct line
{
    double a,b;
    int n;
} l[N], st[N];
int n, top = 0;
double a[N], b[N];
void Readin()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    	scanf("%lf", &b[i]);
    for (int i = 1; i <= n; ++i)
    	scanf("%lf", &a[i]);
    for (int i = 1; i <= n; ++i)
    	l[i].a = a[i], l[i].b = b[i], l[i].n = i;
}

bool cmp(const line a,const line b)
{
    if (fabs(a.a - b.a) < eps)
        return a.b < b.b;
	return a.a < b.a;
}
double Bfw(line a,line b)
{
    return (b.b - a.b) / (a.a - b.a);
}
bool Cross(line a, line b)
{
	double x = (b.b - a.b) / (a.a - b.a);
	return x >= 0;
}

void Insert(line a)
{
	while (top && fabs(a.a - st[top].a) < eps && fabs(a.b - st[top].b) > eps)
		--top;
	if (fabs(a.a - st[top].a) > eps)
	{
		while (top && !Cross(a, st[top]))
			--top;
		while (1 < top && Bfw(a,st[top - 1]) < Bfw(st[top - 1],st[top]))
			--top;
	}
    st[++top] = a;
}
vector<int> ans;
void Work()
{
    sort(l + 1, l + n + 1, cmp);
    st[0].a = -1; 
    for (int i = 1; i <= n; ++i)
        Insert(l[i]);
    ans.clear();
    for (int i = 1; i <= top; ++i)
    	ans.push_back(st[i].n);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0, lim = ans.size(); i < lim; ++i)
    	printf("%d%c", ans[i], i + 1 == lim ? '\n' : ' ');
}
int main()
{
    Readin();
    Work();
    return 0;
}
