#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
map<int, int> mp;
int a[5][5];
int ha()
{
    int res = 0;
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
            res = res * 3 + a[i][j];
    return res;
}
inline int xie1(int x, int y)
{
    return a[x][y] == a[x + 1][y + 1] && a[x][y] == a[x + 2][y + 2];
}
inline int xie2(int x, int y)
{
    return a[x][y] == a[x - 1][y + 1] && a[x][y] == a[x - 2][y + 2];
}

int win()
{
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 2; ++j)
        {
            bool flag = true;
            for (int k = 0; k < 3; ++k)
            {
                if (a[i][j] != a[i][j + k])
                    flag = false;
            }
            if (a[i][j] && flag)
                return a[i][j];
        }
    }
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            bool flag = true;
            for (int k = 0; k < 3; ++k)
            {
                if (a[i][j] != a[i + k][j])
                    flag = false;
            }
            if (a[i][j] && flag)
                return a[i][j];
        }
    }
    if (a[1][2] && xie1(1, 2))
        return a[1][2];
    if (a[1][1] && xie1(1, 1))
        return a[1][1];
    if (a[2][2] && xie1(2, 2))
        return a[2][2];
    if (a[2][1] && xie1(2, 1))
        return a[2][1];
    
    if (a[3][2] && xie2(3, 2))
        return a[3][2];
    if (a[3][1] && xie2(3, 1))
        return a[3][1];
    if (a[4][2] && xie2(4, 2))
        return a[4][2];
    if (a[4][1] && xie2(4, 1))
        return a[4][1];

    return 0;
}
int x, y, ans = 0;
void dfs(int now, bool flag)
{
    int sta = win();
    if (sta == 1)
        return;
    if (sta == 2)
    {
        if (flag)
        {
            if (mp[ha()])
                return;
            mp[ha()] = 1;
            ++ans;
        }
        return;
    }
    if (flag)
        return;
    for (int i = 1; i <= 4; ++i)
    {
        if (a[i][0] == 4)
            continue;
        a[i][++a[i][0]] = now + 1;
        dfs(now ^ 1, i == x && a[i][0] == y);
        a[i][a[i][0]--] = 0;
    }
}
int main()
{
    mp.clear();
    int t;
    scanf("%d%d%d", &t, &y, &x);
    memset(a, 0, sizeof a);
    a[t][++a[t][0]] = 0 + 1;
    dfs(1, x == t && y == 1);
    printf("%d\n", ans);
    return 0;
}