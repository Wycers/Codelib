#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q, tmp;
void solve()
{
    int n;
    scanf("%d", &n);
    q = tmp;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        q.push(x);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int opt, x;
        scanf("%d", &opt);
        if (opt == 1)
        {
            scanf("%d", &x);
            q.push(x);    
        }
        else if (opt == 2)
            q.pop();
        else
            printf("%d\n", q.top());
    }
}
int main()
{
    while (!tmp.empty())
        tmp.pop();
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}