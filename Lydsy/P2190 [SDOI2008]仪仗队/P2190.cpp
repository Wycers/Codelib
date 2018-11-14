#include<stdio.h>
#include<string.h>
#define M 40005
int prime[M],phi[M];
bool flag[M];
int n;

void get_prime()
{
    int i,j,k;
    memset(flag,false,sizeof(flag));
    k=0;
    for(i=2;i<M;i++)
    {
        if(!flag[i])
        {
            prime[k++]=i;
            phi[i]=i-1;
        }
        for(j=0;j<k&&i*prime[j]<M;j++)
        {
            flag[i * prime[j]] = true;
            if(i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                    break;
            }
            else
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}
int main()
{
    scanf("%d",&n);
    get_prime();
    int ans = 0;
    for(int i=1;i<n;i++)
       ans += phi[i];
    printf("%d",2 * ans + 3);
    return 0;
}
