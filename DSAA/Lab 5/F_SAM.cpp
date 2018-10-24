#include <cstdio>
#include <cstring>
#include <algorithm>
   
const int N = 4e2 + 10;
using namespace std;
   
int P[N], num[N], mv[N];
struct sam
{
    int p, q, np, nq;
    int cnt = 1, last = 1;
    int ch[N][26], mx[N], fa[N], chr[N];
    inline int new_node(int x)
    {
        mx[++cnt] = x;
        return cnt;
    }
    void extend(int x, int pos)
    {
        p = last;
        np = new_node(mx[p] + 1);
        chr[np] = pos;
        for (; p && !ch[p][x]; p = fa[p])
            ch[p][x] = np;
        if (!p)
            fa[np] = 1;
        else
        {
            q = ch[p][x];
            if (mx[q] == mx[p] + 1)
                fa[np] = q;
            else
            {
                nq = new_node(mx[p] + 1);
                chr[nq] = pos;
                memcpy(ch[nq], ch[q], sizeof ch[nq]);
                fa[nq] = fa[q], fa[q] = fa[np] = nq;
                for (; ch[p][x] == q; p = fa[p])
                    ch[p][x] = nq;
            }
        }
        last = np;
    }
    void build(char *str)
    {
        memset(mv, 0, sizeof mv);
        memset(ch, 0, sizeof ch);
        cnt = last = 1;
        for (int i = 0, len = strlen(str); i < len; ++i)
            extend(str[i] - 'a', i);
        for (int i = 1; i <= cnt; ++i)
            mv[mx[i]]++;
        for (int i = 1, len = strlen(str); i <= len; ++i)
            mv[i] += mv[i - 1];
        for (int i = 1; i <= cnt; ++i)
            P[mv[mx[i]]--] = i;
    }
    void solve(char *str)
    {
        for (int i = 0, p = 1, l = 0, len = strlen(str); i < len; ++i)
        {
            int x = str[i] - 'a';
            if (ch[p][x])
                l++, p = ch[p][x];
            else
            {
                for (; p && !ch[p][x]; p = fa[p]);
                if (!p)
                    l = 0, p = 1;
                else
                    l = mx[p] + 1, p = ch[p][x];
            }
            num[p] = max(num[p], l);
        }
        for (int i = cnt; i > 1; i--)
        {
            int x = P[i];
            mv[x] = min(mv[x], num[x]);
            if (fa[x] && num[x])
                num[fa[x]] = mx[fa[x]];
            num[x] = 0;
        }
    }
} sam;
   
char ori[210], str[210];
int n;
void solve()
{
    scanf("%d", &n);
    scanf("%s", ori);
    sam.build(ori);
    memset(mv, 0x3f, sizeof mv);
    while (--n)
    {
        scanf("%s", str);
        sam.solve(str);
    }
    int len = 0;
    for (int i = 2; i <= sam.cnt; ++i)
        if (mv[i] > len)
            len = mv[i];
    if (len == 0)
    {
        puts("Hong");
        return;
    }
    char ans[210] = "";
    for (int i = 2; i <= sam.cnt; ++i)
        if (mv[i] == len && (strlen(ans) == 0 || strncmp(ans, ori + sam.chr[i] - len + 1, len) > 0))
            strncpy(ans, ori + sam.chr[i] - len + 1, len);
    printf("%s\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}