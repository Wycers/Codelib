#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 150010;
struct node
{
    int l, r;
} tr[N];
int fa[N];
queue<int> q;
bool solve()
{
    int n;
    scanf("%d", &n);
    memset(fa, 0, sizeof fa);
    for (int i = 1; i <= n; ++i)
    {

        scanf("%d%d", &tr[i].l, &tr[i].r);
        fa[tr[i].l] = i;
        fa[tr[i].r] = i;
    }
    int root = 1;
    while (fa[root])
        root = fa[root];

    while (!q.empty())
        q.pop();
    q.push(root);

    bool flag = false;
    while (!q.empty())
    {
        int x = q.front(); 
        if (x == 0)
            flag = true;
        else
        {
            if (flag)
                return false;
            q.push(tr[x].l);
            q.push(tr[x].r);
        }
        q.pop();
    }
    return true;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        puts(solve() ? "Yes" : "No");
    return 0;
}