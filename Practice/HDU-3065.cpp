#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int nx[55 * 1010][128], fail[55 * 1010], id[55 * 1010], top = 0;

int newnode()
{
    for (int i = 0; i < 128; i++)
        nx[top][i] = -1;
    id[top] = -1;   
    return top++;
}
int root = newnode();
void insert(char *str, int idd)
{
    int p = root;
    for (int i = 0, len = strlen(str); i < len; ++i)
    {
        if (nx[p][str[i]] == -1)
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
    fail[root] = root;
    for (int i = 0; i < 128; i++)
    {
        if (nx[root][i] == -1)
        {
            nx[root][i] = root;
            continue;
        }
        fail[nx[root][i]] = root;
        q.push(nx[root][i]);
    }
    while (!q.empty())
    {
        int now = q.front(); q.pop();
        for (int i = 0; i < 128; i++)
        {
            if (nx[now][i] == -1)
            {
                nx[now][i] = nx[fail[now]][i];
                continue;
            }
            fail[nx[now][i]] = nx[fail[now]][i];
            q.push(nx[now][i]);
        }
    }
}
int ans[1010];
void ac_automation(char *str)
{
    int p = root;
    for (int i = 0, len = strlen(str); i < len; i++)
    {
        p = nx[p][str[i]];
        for (int now = p; now != root; now = fail[now])
            if (id[now] != -1)
                ++ans[id[now]];
    }
}
char origin[1010][100];
char str[2000010];
int main()
{
    freopen("test.in", "r", stdin);
    int n;
    while(scanf("%d",&n) == 1)
    {
        top = 0;
        root = newnode();
        for(int i = 0;i < n;i++)
        {
            scanf("%s",origin[i]);
            insert(origin[i],i);
        }
        getfail();
        scanf("%s", str);
        memset(ans, 0, sizeof ans);
        ac_automation(str);
        for (int i = 0; i < n; ++i)
            if (ans[i] > 0)
                printf("%s: %d\n", origin[i], ans[i]);
    }
    return 0;
}
