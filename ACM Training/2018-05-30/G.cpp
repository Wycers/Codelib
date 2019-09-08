#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5 + 10;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}

int n, x, y, a[N], cnt[N];
bool modify[N];

vector<int> fact(int x) 
{
    vector<int> res;
    res.clear();
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            res.push_back(i);
            while (x % i == 0)  x /= i;
        }
    }
    if (x != 1)
        res.push_back(x);
    return res;
}
void solve()
{
    n = read(); x = read(); y = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();

    if (y % x) {
        puts("-1");
        return;
    }
    if (n == 1 && y != x) {
        puts("-1");
        return;
    }

    vector<int> fac = fact(y);
    vector<int> cntx, cnty;
    cntx.resize(fac.size());
    cnty.resize(fac.size());
    
    for(int i = 0; i < fac.size(); ++i)
    {
        while(x % fac[i] == 0)
            x /= fac[i], ++cntx[i];
        while(y % fac[i] == 0)
            y /= fac[i], ++cnty[i];
    }

    bool flag1 = false, flag2 = false;
    memset(modify, false, sizeof(modify));
    for (int t = 0; t < fac.size(); ++t)
    {
        int mx = 0, mn = 1000;
        for (int i = 1; i <= n; ++i)
        {
            cnt[i] = 0;
            while (a[i] % fac[t] == 0)
            {
                ++cnt[i];
                a[i] /= fac[t];
            }
            mx = max(mx, cnt[i]);
            mn = min(mn, cnt[i]);
        }
            
        if (mn > cntx[t])
            flag1 = true;
        else if (mn < cntx[t])
            for (int i = 1; i <= n; ++i)
                if (cnt[i] < cntx[t])
                    modify[i] = true;
                
        if (mx < cnty[t])
            flag2 = true;
        else if (mx > cnty[t]) 
            for (int i = 1; i <= n; ++i)
                if (cnt[i] > cnty[t])
                    modify[i] = true;
    }
    for (int i = 1; i <= n; ++i)
        if (a[i] != 1)
            modify[i] = true;
            
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (modify[i])
            ++ans;
    ans = max(ans, flag1 + flag2);
    printf("%d\n", ans);
}
int main()
{
    for (int T = read(); T; --T)
        solve();
    return 0;
}