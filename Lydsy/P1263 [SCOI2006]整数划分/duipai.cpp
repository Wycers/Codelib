#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,l=1,d[3000],ans[3000]={1};
int get(int x)
{
    if(x>=1000)return 4;
    if(x>=100)return 3;
    if(x>=10)return 2;
    else return 1;
    }
void cal(int x)
{
     for(int i=0;i<l;i++)ans[i]*=x;
     for(int i=0;i<l;i++)
     {
        ans[i+1]+=ans[i]/10000;
        ans[i]%=10000;
        }
     while(ans[l]>0){ans[l+1]+=ans[l]/10000;ans[l]%=10000;l++;}
     }
int main()
{
    scanf("%d",&n);
    while(n>4){n-=3;cal(3);}cal(n);
    for(int i=0;i<l;i++)d[i]=get(ans[i]);
    printf("%d\n",(l-1)*4+d[l-1]);
    printf("%d",ans[l-1]);
    int i;
    for(i=l-2;i>=max(0,l-25);i--)
    {
            for(int j=d[i];j<4;j++)printf("0");
            printf("%d",ans[i]);
            }
    if(i>=0)
    {
            if(d[l-1]==3)printf("%d",ans[i]/1000);
            else if(d[l-1]==2){if(ans[i]<10)printf("0");printf("%d",ans[i]/100);}
            else if(d[l-1]==1)
            {
                 if(ans[i]<100)printf("0");
                 if(ans[i]<10)printf("0");
                 printf("%d",ans[i]/10);
                 }
            }
    return 0;
    }

//1655250603440005649037880647211190189401999400607767622047923050419092278684323568159475343296082530
