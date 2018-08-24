#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int nx[210 * 500][128], fail[210 * 500], id[210 * 500], top = 1;

int newnode()
{
    for (int i = 0; i < 128; i++)
        nx[top][i] = 0;
    id[top] = 0;
    return top++;
}
int root = newnode();
void insert(char *str, int idd)
{
    int p = root;
    for (int i = 0, len = strlen(str); i < len; ++i)
    {
        if (nx[p][str[i]] == 0)
            nx[p][str[i]] = newnode();
        p = nx[p][str[i]];
    }
    id[p] = idd;
}
queue<int> q;
void getfail()
{
    while (!q.empty())
        q.pop();
    q.push(root);
    while (!q.empty())
    {
        int now = q.front(); q.pop();
        for (int i = 0; i < 128; ++i)
        {
            if (nx[now][i] == 0)
                continue;
            if (now == root)
                fail[nx[now][i]] = root;
            else 
            {
                int p;
                for (p = fail[now]; p; p = fail[p])
                    if (nx[p][i] != 0)
                    {
                        fail[nx[now][i]] = nx[p][i];
                        break;
                    }
                if (p == 0)
                    fail[nx[now][i]] = root;
            }
            q.push(nx[now][i]);
        }
    }
}
bool used[501];
void ac_automation(char *str)
{
    int p = root;
    for (int i = 0, len = strlen(str); i < len; ++i)
    {
        while (!nx[p][str[i]] && p != root)
            p = fail[p];
        p = nx[p][str[i]];
        if (!p)
            p = root;
        for (int now = p; now != root; now = fail[now])
        {
            if (id[now] != 0)
            {
                used[id[now]] = true;
                used[0] = true;
            }
        }
            
    }
}
char str[10010];
int main()
{
    freopen("test.in", "r", stdin);
    int n, m, ans = 0;

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