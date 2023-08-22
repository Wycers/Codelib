#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e4 + 10;
struct Treenode
{
    Treenode *left, *right;
    int val;
    Treenode () 
    {
        left = right = NULL;
    }
} tr[N];
void pre(Treenode *now)
{
    if (now == NULL)
        return;
    printf("%d ", now->val);
    pre(now->left);
    pre(now->right);
}
void mid(Treenode *now)
{
    if (now == NULL)
        return;
    mid(now->left);
    printf("%d ", now->val);
    mid(now->right);
}
void post(Treenode *now)
{
    if (now == NULL)
        return;
    post(now->left);
    post(now->right);
    printf("%d ", now->val);
}
void solve()
{
    int n; 
    memset(tr, 0, sizeof tr);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        tr[i].val = i;
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (tr[x].left == NULL)
            tr[x].left = tr + y;
        else 
            tr[x].right = tr + y;
    }
    pre(tr + 1);
    puts("");
    mid(tr + 1);
    puts("");
    post(tr + 1);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}