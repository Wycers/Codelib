#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1e5+5;
char s1[maxn], s2[maxn],s[maxn*2];
int nex[maxn*2];
void getnext(int m)
{
    int j = 0, k = -1;
    nex[0] = -1;
    while(j < m)
    {
        if(k == -1 || s[j] == s[k]) nex[++j] = ++k;
        else k = nex[k];
    }
    //for(int i = 0; i <= m; i++) cout<<nex[i]<<endl;
}
int main(void)
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int l1,l2,l;
        scanf("%d%d%s%s",&l1,&l2,s1,s2);
        for(int i = 0; i < l1; i++) s[i] = s1[i];
        for(int i = 0; i < l2; i++) s[i+l1] = s2[i];
        l = l1+l2;
        getnext(l);
        if(nex[l])
        {
            //cout<<nex[l]<<endl;
            while((l>l1 || l>l2)) l = nex[l];
            if(l <= 0)
            {
                printf("0\n");
                continue;
            }
            printf("%d ",l);
            for(int i = 0; i < l; i++)
                printf("%c",s[i]);
            printf("\n");
        }
        else printf("0\n");
    }
    return 0;
}