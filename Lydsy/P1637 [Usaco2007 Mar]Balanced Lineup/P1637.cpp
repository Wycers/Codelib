#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 50000 + 10;
using namespace std;

int pos[N],l[N],type[N],tag[N];
int n;
void Readin()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        tag[i] = i;
        scanf("%d%d",type + i,pos + i);
        if (type[i] == 0)
            --type[i];
    }
}

bool cmp(int a,int b)
{
    return pos[a] < pos[b];
}
void Work()
{
    int ans = 0,sum = 0;
    sort(tag + 1,tag + n + 1,cmp);
    memset(l,0x7f,sizeof(l));
    for (int i=1;i<=n;++i)
    {
        l[sum] = min(l[sum],pos[tag[i]]);
        sum += type[tag[i]];
        ans = max(ans,pos[tag[i]] - l[sum]);
    }
    printf("%d\n",ans);

}
int main()
{
    Readin();
    Work();
    return 0;
}
