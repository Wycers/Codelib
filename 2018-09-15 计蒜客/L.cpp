#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;
const int N = 110;
const int Ha = 1e9 + 7;
int id[128];
struct AC_Automation {
    int nx[N][3], fail[N], top, root, flag[N];
    int newnode()
    {
        for (int i = 0; i < 3; ++i)
            nx[top][i] = -1;
        flag[top] = false;
        return top++;
    }
    void clear()
    {
        top = 0;
        root = newnode();
        memset(fail, 0, sizeof fail);
    }
    void insert(char *str)
    {
        int p = root;
        for (int i = 0, len = strlen(str); i < len; ++i)
        {
            int ch = id[str[i]];
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
        for (int i = 0; i <3; ++i)
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
            for (int i = 0; i < 3; ++i)
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

struct Mat {
    ll n, m, mat[N][N];
    Mat ()
    {
        n = 0, m = 0;
        memset(mat, 0, sizeof mat);
    }
}; 
inline void add(long long &a, long long x)
{
    a += x;
    while (a >= Ha)
        a -= Ha;
}
Mat operator * (const Mat &a, const Mat &b) 
{
    Mat c;
    c.n = a.n, c.m = b.m;
    for (int i = 0; i < c.n; ++i)
        for (int j = 0; j < c.m; ++j)
            for (int k = 0; k < a.m; ++k)
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % Ha;
    return c;
}
char str[N];
Mat res, bak;
ll walk(ll n)
{
    Mat x = bak;
    while (n)
    {
        if (n & 1)
            res = res * x;
        x = x * x;
        n >>= 1;
    }
    ll ans = 0;
    for (int i = 0; i < AC.top; ++i)
        ans = (ans + res.mat[0][i]) % Ha;
    return ans;
}
ll input[1000], rk[1000], tg[1000], ans[1000];
inline bool cmp(const int &a, const int &b)
{
    return input[a] < input[b];
}
int main()
{   
    id['F'] = 0; id['C'] = 1; id['M'] = 2; 
    AC.clear();
    AC.insert("FFF");
    AC.insert("CCC");
    AC.insert("MMM");

    AC.insert("FCM");
    AC.insert("MCF");

    AC.insert("CFC");
    AC.insert("CMC");
    AC.getfail();
    for (int i = 0; i < AC.top; ++i)
        res.mat[i][i] = 1;
    res.n = res.m = bak.n = bak.m = AC.top;
    for (int i = 0; i < AC.top; ++i)
        for (int j = 0; j < 3; ++j)
        {
            if (AC.flag[AC.nx[i][j]])
                continue;
            ++bak.mat[i][AC.nx[i][j]];
        }

    int T; scanf("%d", &T);
    for (int i = 0; i < T; ++i)
        scanf("%lld", input + i);
    for (int i = 0; i < T; ++i)
        rk[i] = i;
    sort(rk, rk + T, cmp);
    for (int i = 0; i < T; ++i)
        tg[rk[i]] = i;

    for (int i = 0; i < T; ++i)
    {
        if (i == 0)
            ans[rk[i]] = walk(input[rk[i]]);
        else
            ans[rk[i]] = walk(input[rk[i]] - input[rk[i - 1]]);
    }
    for (int i = 0; i < T; ++i)
        printf("%lld\n", ans[i]);

    return 0;
}