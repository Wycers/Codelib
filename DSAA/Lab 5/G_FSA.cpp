#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
struct FSA {
    int nx[N][26], from[N], now, len, last = 0, top;
    void build(char *str)
    {
        from[0] = 0;
        memset(nx, 0, sizeof nx);
        len = strlen(str); now = 0;
        for (int i = 0; i < len; ++i)
        {
            int ch = str[i] - 'a';
            for (int c = 0; c < 26; ++c)
                nx[i][c] = ch == c ? i + 1 : nx[last][c];
            if (i != 0)
                last = nx[last][ch];
        }
        for (int c = 0; c < 26; ++c)
            nx[len][c] = nx[last][c];
    }
    void walk(int ch)
    {
        from[++top] = now;
        now = nx[now][ch];
    }
    int getans()
    {
        return len - now;
    }
    void goback()
    {
        if (top)
            now = from[top--];
        else
            now = 0;
    }
} fsa[4];
int n, ans[N];
char str[N];
int getans()
{
    int res = 0x3f3f3f3f;
    for (int i = 0; i < n; ++i)
        res = min(res, fsa[i].getans());
    return res;
}
void work(int ch)
{
    for (int i = 0; i < n; ++i)
        fsa[i].walk(ch);
}
void goback()
{
    for (int i = 0; i < n; ++i)
        fsa[i].goback();
}
int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%s", str);
        fsa[i].build(str);
    }
    printf("%d\n", getans());
    scanf("%s", str);
    for (int i = 0, len = strlen(str); i < len; ++i)
    {
        if (str[i] == '-') 
            goback();
        else
            work(str[i] - 'a');
        printf("%d\n", getans());
    }
    return 0;
}