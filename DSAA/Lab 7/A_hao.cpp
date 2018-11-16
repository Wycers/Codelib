#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 150005;
int n, f, s, son[maxn][2], sum[maxn], vis[maxn];
bool complete, flag;
int dfs_mx(int p, int deep)
{
    if (p == 0)
        return 0;
    sum[deep]++;
    return max(max(dfs_mx(son[p][0], deep + 1), dfs_mx(son[p][1], deep + 1)), deep);
}
void dfs(int p, int deep, int mxd)
{
    if (deep >= mxd)
        return;
    if (deep == mxd - 1)
        if (complete)
        {
            if (son[p][0])
                if (son[p][1])
                    return;
                else
                    complete = false;
            else
                if (son[p][1])
                    flag = false;
                else
                    complete = false;
        }
        else
            if (son[p][0] + son[p][1])
                flag = false;
    if (flag == false)
        return;
    dfs(son[p][0], deep + 1, mxd);
    dfs(son[p][1], deep + 1, mxd);
}
int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        flag = true;
        complete = true;
        scanf("%d", &n);
        memset(sum, 0, sizeof sum);
        memset(vis, 0, sizeof vis);
    
        for (int i = 1; i <= n; i++)
        {
            son[i][0] = son[i][1] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &son[i][0], &son[i][1]);
            vis[son[i][0]] = 1;
            vis[son[i][1]] = 1;
        }
        bool istree = false;
        for (int i = 1; i <= n; i++)
            if (vis[i] == 0)
            {
                if (istree)
                    flag = false;
                istree = true;
                int mxd = dfs_mx(i, 0);
                for (int j = 0; j < mxd; j++)
                    if (sum[j] != (1 << j))
                    {
                        flag = false;
                        break;
                    }
                if (flag)
                    dfs(i, 0, mxd);
            }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}