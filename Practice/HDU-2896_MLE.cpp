#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
struct node {
    node *next[128], *fail;
    int *id;
    node () {
        for (int i = 0; i < 128; ++i)
        {
            next[i] = NULL;
            delete next[i];
        }
        id = NULL;
        delete id;
        fail = NULL;
        delete fail;
    }
} *root;
void insert(char *str, int id)
{
    node *p = root;
    for (int i = 0, len = strlen(str); i < len; ++i)
    {
        if (p->next[str[i]] == NULL)
            p->next[str[i]] = new node;
        p = p->next[str[i]];
    }
    p->id = new int(id);
}
queue<node*> q;
void getfail()
{
    while (!q.empty())
        q.pop();
    q.push(root);
    while (!q.empty())
    {
        node* now = q.front(); q.pop();
        for (int i = 0; i < 128; ++i)
        {
            if (!now->next[i])
                continue;
            if (now == root)
                now->next[i]->fail = root;
            else 
            {
                node *p;
                for (p = now->fail; p; p = p->fail)
                    if (p->next[i])
                    {
                        now->next[i]->fail = p->next[i];
                        break;
                    }
                if (p == NULL)
                    now->next[i]->fail = root;
            }
            q.push(now->next[i]);
        }
    }
}
bool used[501];
void ac_automation(char *str)
{
    node* p = root;
    for (int i = 0, len = strlen(str); i < len; ++i)
    {
        while (!p->next[str[i]] && p != root)
            p = p->fail;
        p = p->next[str[i]];
        if (!p)
            p = root;
        for (node* now = p; now != root; now = now->fail)
            if (now->id)
            {
                used[*now->id] = true;
                used[0] = true;
            }
    }
}
char str[10001];
int main()
{
    freopen("test.in", "r", stdin);
    int n, m, ans = 0;
    root = new node;

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", str);
        insert(str, i);
    }
    getfail();

    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        memset(used, false, sizeof used);

        scanf("%s", str);
        ac_automation(str);
        if (used[0])
        {
            ++ans;
            printf("web %d:", i);
            for (int j = 1; j <= n; ++j)
                if (used[j])
                    printf(" %d", j);
            puts("");
        }
    }
    printf("total: %d\n", ans);
    return 0;
}