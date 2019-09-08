#include <cstdio>
#include <cstring>
char ch[505];
bool isdight(char c)
{
    return '0' <= c && c <= '9';
}




void solve()
{
    scanf("%s", ch + 1);
    int len = strlen(ch + 1);
    ch[0] = '+'; ch[len + 1] = '+';
    for (int i = 1; i <= len; ++i)
        if (!isdight(ch[i - 1]) && ch[i] == '0' && ch[i + 1] == '?')
            ch[i + 1] = '+';
    for (int i = 1; i <= len; ++i)
        if (ch[i] == '?')
            ch[i] = '1';

    bool valid = true;
    for (int i = 0; i <= len; ++i)
        if (!isdight(ch[i]) && !isdight(ch[i + 1]))
            valid = false;
    for (int i = 1; i <= len; ++i)
        if (!isdight(ch[i - 1]) && ch[i] == '0' && isdight(ch[i + 1]))
            valid = false;

    if (valid)    
    {
        for (int i = 1; i <= len; ++i)
            printf("%c", ch[i]);
        puts("");
    }
    else
        puts("IMPOSSIBLE");
}
int main()
{
      int T; scanf("%d", &T);
    while (T--)
        solve();
      return 0;
}