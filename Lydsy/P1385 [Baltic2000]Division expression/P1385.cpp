#include <cstdio>
using namespace std;
int Gcd(int x,int y)
{
    return y ? Gcd(y,x % y) : x;
}
int T,t,n,a[100001];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&a[1],&t);
        for(int i=1;i<=n-2;i++)
            scanf("%d",a + i + 1);
        for(int i=1;i<n;i++)
        {
            t /= Gcd(t,a[i]);
            if(t == 1)
            {
                printf("YES\n");
                break;
            }
        }
        if(t!=1)
            printf("NO\n");
    }
    return 0;
}
