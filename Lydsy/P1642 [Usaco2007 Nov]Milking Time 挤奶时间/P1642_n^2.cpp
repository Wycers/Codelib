#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1000 + 10;
int n,m,r,f[N];
int s[N],e[N],w[N];
int tag[N];
void Readin()
{
    scanf("%d%d%d",&n,&m,&r);
    for (int i=1;i<=m;++i)
        scanf("%d%d%d",s + i,e + i,w + i);
}
bool cmp(const int a,const int b)
{
    return s[a] < s[b];
}
void Dp()
{
    for (int i=1;i<=m;++i)
        tag[i] = i;
    sort(tag + 1,tag + m + 1,cmp);
    int ans = 0;
    for (int i=1;i<=m;++i)
    {
        f[i] = w[tag[i]];
        for (int j=1;j<i;++j)
            if (e[tag[j]] + r <= s[tag[i]])
                f[i] = max(f[i],f[j] + w[tag[i]]);
        ans = max(f[i],ans);
    }
    printf("%d\n",ans);
}
int main()
{
    Readin();
    Dp();
    return 0;
}
