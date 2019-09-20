#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
struct AC_Automation {
    int nx[N][26], fail[N], top, root, flag[N];
    int newnode()
    {
        for (int i = 0; i < 26; ++i)
            nx[top][i] = -1;
        flag[top] = false;
        return top++;
    }
    void clear()
    {
        top = 0;
        root = newnode();
        memset(fail, 0, sizeof fail);
        memset(flag, 0, sizeof flag);
    }
    void insert(char *str)
    {
        int p = root;
        for (int i = 0, len = strlen(str); i < len; ++i)
        {
            int ch = str[i] - 'a';
            if (nx[p][ch] == -1)
                nx[p][ch] = newnode();
            p = nx[p][ch];
        }
        flag[p] = true;
    }
    queue<int> q;
    void getfail()
    {
        while (!q.empty())
            q.pop();
        fail[root] = root;
        for (int i = 0; i < 26; ++i)
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
            if (flag[fail[now]] == true)
                flag[now] = true;
            for (int i = 0; i < 26; ++i)
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
} AC;

queue<int> q;
int ans[N];
struct Edge
{
    int to, next;
} edge[26 * N];
int head[26 * N], cnt = 0;
void insert(int u, int v)
{
    edge[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
void spfa()
{
    memset(ans, 0, sizeof ans);
    while (!q.empty())
        q.pop();
    for (int i = 0; i < AC.top; ++i)
    {
        if (AC.flag[AC.fail[i]])
            AC.flag[i] = true;
        if (AC.flag[i])
        {
            ans[i] = 1;
            q.push(i);
        }
    }
    for (int i = 0; i < AC.top; ++i)
        for (int j = 0; j < 26; ++j)
            if (AC.nx[i][j] != -1)
                insert(AC.nx[i][j], i);
    
    while (!q.empty())
    {
        int now = q.front(); q.pop();
        for (int i = head[now]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (ans[v])
                continue;
            ans[v] = ans[now] + 1;
            q.push(v);
        }
    }
}

char str[N];
int n, st[N];
int main()
{
    scanf("%d", &n);

    AC.clear();
    while (n--) 
    {
        scanf("%s", str);
        AC.insert(str);
    }
    AC.getfail();
    spfa();
    
    scanf("%s", str);
    int now = 0;
    memset(st, 0, sizeof st);
    printf("%d\n", ans[st[now]] - 1);
    for (int i = 0, len = strlen(str); i < len; ++i)
    {
        if (str[i] == '-') 
            now = max(now - 1, 0);
        else
        {
            int k = AC.nx[st[now]][str[i] - 'a'];
            if (k == -1)
                k = AC.root;
            st[++now] = k;
        }

        printf("%d\n", ans[st[now]] - 1);
    }
    return 0;
}