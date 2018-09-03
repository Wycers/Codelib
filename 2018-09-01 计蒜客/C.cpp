#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxm = 20005;
const int maxn = 205;
int T, n, m;
int card_stack[maxm], card[maxn][15], cnt[maxn], tot, ans[maxn]; //牌库 手牌 每个人的手牌数 当前牌库状态
void init()
{
    tot = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(card, 0, sizeof(card));
    memset(ans, 0, sizeof ans);
}
void print(int x)
{
    printf("Case #%d:\n", x);
    for (int i = 0; i < n; i++)
        if (ans[i])
            printf("%d\n", ans[i]);
        else
            printf("Winner\n");
}
void start(int x, int num) //抽牌，从第x个人开始进行一轮抽牌，每人抽num张牌
{
    if (tot >= m)
        return;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < num; j++)
            if (tot < m)
            {
                card[(x + i) % n][card_stack[tot++]]++, cnt[(x + i) % n]++;
            }
}
pair<int, int> play(pair<int, int> pre, int x) //first:上一个出牌id second:上一张出的牌
{
    if (pre.second == -1) //没有前一个人
    {
        pre.first = x;
        for (int i = 0; i < 13; i++)
        {
            int t = (3 + i) > 13 ? 3 + i - 13 : 3 + i;
            if (card[x][t])
            {
                cnt[x]--;
                card[x][t]--;
                pre.second = t;
                break;
            }
        }
        if (cnt[x] == 0)
            return make_pair(x, 0);
        else
            return pre;
    }
    int t = pre.second == 13 ? 1 : pre.second + 1;
    if (pre.second == 2 || (card[x][t] == 0 && card[x][2] == 0)) //无法出牌
    {
        if (x == pre.first)
        {
            start(x, 1);
            return play(make_pair(0, -1), x);
        }
        return pre;
    }
    pre.first = x;
    cnt[x]--;
    if (card[x][t] != 0)
    {
        card[x][t]--;
        pre.second = t;
    }
    else
    {
        card[x][2]--;
        pre.second = 2;
    }
    if (cnt[x] == 0)
        pre.second = 0;
    return pre;
}
void solve()
{
    start(0, 5);
    int x = 0;
    pair<int, int> y = make_pair(0, -1);
    while (y.second != 0)
    {
        y = play(y, x);
        x = (x + 1) % n;
    }
    //结算
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= 13; j++)
            ans[i] += card[i][j] * j;
}
int main()
{
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        init();
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
            scanf("%d", &card_stack[i]);
        solve();
        print(i);
    }
}