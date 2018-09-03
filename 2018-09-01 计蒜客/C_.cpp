#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int M = 20005;
const int N = 205;
int T, n, m;
int card_stack[M], tot; //牌库 手牌 每个人的手牌数 当前牌库状态
struct player
{
    int cnt, card[13];
    void init()
    {
        memset(card, 0, sizeof card);
        cnt = 0;
    }
    player() { init(); }
    int score()
    {
        int res = 0;
        for (int i = 0; i < 13; ++i)
            res += card[i] * (i + 1);
        return res;
    }
    void getcard(int cnt)
    {
        if (tot >= m)
            return;
        while (cnt--)
            ++card[card_stack[tot++]];
        for (int i = 0; i <13 ; ++i)
            printf("%d ", card[i]);
        puts("");
    }
    void da(int x)
    {
        if (card[x] == 0)
            return;
        --card[x];
        --cnt;
    }
    int play(int x) // 他看着这张 x 的牌，思考自己要出什么牌。 0 表示没出。
    {
        if (x == -1)
        {
            for (int i = 0; i < 13; i++)
            {
                int t = (3 + i) > 13 ? 3 + i - 13 : 3 + i;
                if (card[t])
                {
                    da(t);
                    return t;
                }
            }
        }
        if (x == 2)
            return 0;
        int t = x == 13 ? 1 : x + 1;
        printf("==>%d\n", t);
        if (card[t])
        {
            da(t);
            return t;
        }
        else if (card[2])
        {
            da(2);
            return 2;
        }
        else 
            return 0;
    }
} p[N];
void init()
{
    tot = 0;
    for (int i = 0; i < n; ++i)
        p[i].init();
}
void getcard(int x, int cnt)
{
    if (tot >= m)
        return;
    for (int i = 0; i < n; ++i)
        p[(x + i) % n].getcard(cnt);
}

void solve()
{
    int now = 0, pre = -1, last = 0;
    getcard(0, 5);
    while (true)
    {
        int i = 0;
        pre = -1;
        for (i = 0; i < n; ++i)
        {
            int c = p[(last + i) % n].play(pre);
            if (c != 0)
            {
                pre = c;
                last = i;
            }
            if (c == 2)
            {
                getcard(last, 1);
                break;
            }
        }
        if (i == n)
            getcard(last, 1);
        for (int i = 0; i < n; ++i)
            if (p[i].cnt == 0)
                break;
    }

    for (int i = 0; i < n; i++)
        if (p[i].cnt == 0)
            puts("Winner");
        else 
            printf("%d\n", p[i].score());
}
int main()
{
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        init();
        scanf("%d%d", &n, &m);
        for (int j = 0; j < m; j++)
            scanf("%d", &card_stack[j]);
        printf("Case #%d:\n", i);
        solve();
    }
}