#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>

using namespace std;
const int N = 1e6 + 10;
const double eps = 1e-8;
const int Inf = 0x3f3f3f3f;
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int n, x[N], y[N], h[N], tag[N]; double angle[N];
void readin()
{
    x[0] = read(); y[0] = read();
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        x[i] = read() - x[0];
        y[i] = read() - y[0];
        h[i] = read();
        angle[i] = atan2(y[i], x[i]);
        tag[i] = i;
    }
}
double dis(int i)
{
    return sqrt(1.0 * x[i] * x[i] + 1.0 * y[i] * y[i]);
}
bool cmp(int i, int j)
{
    if (fabs(angle[i] - angle[j]) < eps)
        return dis(i) < dis(j);
    return angle[i] < angle[j];
}

vector<int> v[N];  
int f[N], cnt = 0;
void solve()
{
    sort(tag + 1, tag + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
        v[i].clear(); 
    v[++cnt].push_back(h[tag[1]]);
    for (int i = 2; i <= n; i++) {  
        if (fabs(angle[tag[i]] - angle[tag[i - 1]]) > eps)
            ++cnt;  
        v[cnt].push_back(h[tag[i]]);  
    }  
    int ans = 0;  
    for (int i = 1; i <= cnt; i++) {  
        int len = v[i].size();  
        for (int j = 0; j < len; j++) f[j] = Inf;  
        for (int j = 0; j < len; j++) *lower_bound(f, f+len, v[i][j]) = v[i][j];  
        ans += lower_bound(f, f + len, Inf) - f;  
    }  
    printf("%d\n", ans);
}

int main()
{
    readin();
    solve();
    return 0;
}