#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef pair<int, int> PLL;
vector<int> human[maxn];
vector<PLL> wolf;
int Far[maxn];
int n;
void init()
{ //初始化
    for (int i = 1; i <= n; i++)
    {
        Far[i] = i;
    }
    wolf.clear();
    for (int i = 0; i <= n; i++)
    {
        human[i].clear();
    }
}
int Find_F(int x)
{ //并查集找爸爸
    if (Far[x] == x)
        return x;
    else
        return Far[x] = Find_F(Far[x]);
}
void unit(int x, int y)
{ //并查集合并
    x = Find_F(x);
    y = Find_F(y);
    if (x == y)
        return;
    else
        Far[x] = y;
}
bool same(int x, int y)
{ //判断是否在一个集合
    return Find_F(x) == Find_F(y);
}
int ans = 0;
void dfs(int x)
{ //dfs找指向该点的村民边
    int len = human[x].size();
    for (int i = 0; i < len; i++)
    {
        ans++;
        dfs(human[x][i]);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%d", &n);
        init();
        for (int i = 1; i <= n; i++)
        {
            char str[20];
            int op;
            scanf("%d%s", &op, str);
            if (str[0] == 'v')
            {
                human[op].push_back(i); //反向建边
                unit(op, i);
            }
            else
            {
                wolf.push_back(make_pair(i, op));
            }
        }
        ans = 0;
        int sz = wolf.size();
        for (int i = 0; i < sz; i++)
        {
            int from = wolf[i].first;
            int to = wolf[i].second;
            if (same(from, to))
            {
                ans++;
                dfs(to);
            }
        }
        cout << ans << endl;
    }
    return 0;
}