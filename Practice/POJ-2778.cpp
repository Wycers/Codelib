#include <cstdio>
#include <cstring>
#include <queue>
typedef long long ll;
using namespace std;
const int N = 110;
const int Ha = 100000;
int id[128];
struct AC_Automation {
    int nx[N][4], fail[N], top, root, flag[N];
    int newnode()
    {
        for (int i = 0; i < 4; ++i)
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
        for (int i = 0; i < 4; ++i)
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
            for (int i = 0; i < 4; ++i)
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
int main()
{
    id['A'] = 0; id['C'] = 1; id['G'] = 2; id['T'] = 3;
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        AC.clear();
        while (n--) 
        {
            scanf("%s", str);
            AC.insert(str);
        }
        AC.getfail();
        Mat res, x;
        for (int i = 0; i < AC.top; ++i)
            res.mat[i][i] = 1;
        res.n = res.m = x.n = x.m = AC.top;
        for (int i = 0; i < AC.top; ++i)
            for (int j = 0; j < 4; ++j)
            {
                if (AC.flag[AC.nx[i][j]])
                    continue;
                ++x.mat[i][AC.nx[i][j]];
            }
        while (m)
        {
            if (m & 1)
                res = res * x;
            x = x * x;
            m >>= 1;
        }
        ll ans = 0;
        for (int i = 0; i < AC.top; ++i)
            ans = (ans + res.mat[0][i]) % Ha;
        printf("%lld\n", ans);
    }
    return 0;
}