#include <cstdio>
using namespace std;

struct node
{
    int tag;
    node *last, *next;
} a[100];
int n, m, e;
void init()
{
    int i;
    for (i = 0; i < n - 1; ++i)
        a[i].tag = i, a[i].next = &a[i + 1];
    a[i].tag = i, a[i].next = &a[0];
}
void solve()
{
    scanf("%d%d%d", &n, &m, &e);
    if (n == 1)
    {
        puts("No");
        return;
    }
    init();
    node *now = &a[0];
    while (now->next != now)
    {
        for (int i = 0; i < m - 1; ++i)
            now = now->next;
        if (now->next->tag == e)
        {
            puts("No");
            return;
        }
        now->next = now->next->next;
        now = now->next;
    }
    puts("Yes");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}