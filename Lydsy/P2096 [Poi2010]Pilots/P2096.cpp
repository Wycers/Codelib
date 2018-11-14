#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k;
int a[3000005];
void Readin()
{
    scanf("%d%d",&k,&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
}
int q1[3000005],q2[3000005];
int ans = 1;
void Solve()
{
    int l1 = 1, l2 = 1, r1 = 0, r2 = 0, t = 1;
    for (int i=1;i<=n;i++)
    {
        while (l1 <= r1 && a[i] >= a[q1[r1]])
            r1 --;
        while (l2 <= r2 && a[i] <= a[q2[r2]])
            r2 --;
        q1[++r1] = q2[++r2] = i;
        while (a[q1[l1]] - a[q2[l2]] > k)
            if(q1[l1] < q2[l2])
                t = q1[l1] + 1, l1++;
			else
                t = q2[l2] + 1, l2++;
        ans = max(ans, i - t + 1);
    }
    printf("%d\n",ans);
}
int main()
{
    Readin();
    Solve();
    return 0;
}
