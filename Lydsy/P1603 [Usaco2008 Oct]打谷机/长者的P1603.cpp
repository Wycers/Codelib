#include<cstdio>
int n,x,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&x);scanf("%d",&x);scanf("%d",&x);
        ans ^= x;
    }
    printf("%d",ans);
    return 0;
}
