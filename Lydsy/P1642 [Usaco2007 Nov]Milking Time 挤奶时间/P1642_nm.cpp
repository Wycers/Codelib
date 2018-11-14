#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1000 + 10;

int n,m,R;
int s[N],e[N],w[N];
void Readin()
{
    scanf("%d%d%d",&n,&m,&R);
    int temp = 0;
    for (int i=1;i<=m;++i)
    {
        scanf("%d%d%d",s + i,e + i,w + i);
        temp = max(temp,e[i]);
    }
    n = min(n,temp);
}

int f[1000005];
int tag[1005];
bool cmp(const int a,const int b)
{
    return e[a] < e[b];
}
void Dp()
{
    for (int i=1;i<=m;++i)
        tag[i] = i;
    sort(tag + 1,tag + m + 1,cmp);
    for (int t=1;t<=m;++t)
    {
        int i = tag[t];
        for (int j=e[i];j<=n;++j)
        {
            f[j] = max(f[j],f[j - 1]);
            if (s[i] >= R)
                f[j] = max(f[j],f[s[i] - R] + w[i]);
            else
                f[j] = max(f[j],w[i]);
        }
    }
    printf("%d\n",f[n]);
}
int main()
{
    Readin();
    Dp();
    return 0;
}
