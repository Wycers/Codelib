#include <cstdio>
using namespace std;
int s1,s2,s3,cnt[100];
int main()
{
    scanf("%d%d%d",&s1,&s2,&s3);
    for (int i=1;i<=s1;i++)
        for (int j=1;j<=s2;j++)
            for (int k=1;k<=s3;k++)
                ++cnt[i + j + k];
    int tag = 1;
    for (int i=2;i<=100;i++)
        if (cnt[i] > cnt[tag])
            tag = i;
    printf("%d\n",tag);
    return 0;
}
