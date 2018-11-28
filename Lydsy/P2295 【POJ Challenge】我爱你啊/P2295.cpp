#include <cstdio>
char S[10] = "luvletter";
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while (T--)
    {
        int now=0,ans=0;char ch = getchar();
        while ('a' <= ch && ch <= 'z')
        {
            if(ch == S[now])
            {
                now++;
                if(now == 9)
                    now=0,ans++;
            }
            ch = getchar();
        }
        printf("%d\n",ans);
    }
    return 0;
}
