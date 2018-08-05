#include <cstdio>
#include <cstring>
using namespace std;
const int N = 15;
bool used[N];
int n, a[N], ans, limit;
bool check()
{
    memset(used, false, sizeof(used));
    for (int i = 1; i <= n; ++i)
    {
        int now = a[i];
        while (used[now] == true)
            if ((++now) == n + 1)
                return false;
        used[now] = true;
    }
    return true;
}
void dfs(int k)
{
    if (k == n + 1)
    {
        if (check())
            ++ans;
        return;
    }
    for (int i = 1; i <= limit; ++i)
    {
        a[k] = i;
        dfs(k + 1);
    }   
}
int pow(int g)
{
    int res = 1;
    for (int i = 1; i <= g; ++i)
        res *= g;
    return res;
}
int main()
{
    for (n = 1; n <= 10; ++n)
    {
        for (limit = 1; limit <= 10; ++limit)
        {
            ans = 0;
            dfs(1);
            printf("%d\t", ans);
        }
        printf("\n");
    }
    return 0;
}