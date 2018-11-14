#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define eps 1e-8
using namespace std;
struct line
{
    double a,b;
    int n;
} l[50005];
int n;
void Readin()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&l[i].a,&l[i].b);
        l[i].n = i;
    }
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
line st[50005];
int top = 0;
bool ans[50005];
void Insert(line a)
{
    while (top)
    {
        if (fabs(a.a - st[top].a) < eps)
            top--;
        else if (top > 1 && Bfw(a,st[top - 1]) <= Bfw(st[top - 1],st[top]))
            top--;
        else break;
    }
    st[++top] = a;
}
void Work()
{
    sort(l + 1,l + n + 1,cmp);
    for (int i=1;i<=n;i++)
        Insert(l[i]);
    for (int i=1;i<=top;i++)
        ans[st[i].n] = true;
    for (int i=1;i<=n;i++)
        if (ans[i])
            printf("%d ",i);
    printf("\n");
}
int main()
{
    Readin();
    Work();
    return 0;
}
