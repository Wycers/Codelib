#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<string>
#include<vector>
#include<bitset>
#include<memory>
#include<cstdio>
#include<utility>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#pragma optimize("-O3")

#ifdef Wavator

#define Debug(...) fprintf(stderr, __VA_ARGS__);

#else

#define Debug(...) 98;

#define cerr if (false) cout

#endif

typedef long long ll;

template <typename A> inline void read(A &x) {
    bool f = false;
    x = 0;
    char c;
    for (c = getchar(); !isdigit(c); c = getchar()) {
        if (c == '-') {
            f = true;
        }
    }
    for (; isdigit(c); c = getchar()) {
        x = (x << 1) + (x << 3) + c - '0';
    }
    if (f) {
        x = -x;
    }
}

template <typename A, typename B> inline void read(A &a, B & b) {
    read(a);
    read(b);
}

template <typename A, typename B, typename C> inline void read(A &a, B &b, C &c) {
    read(a);
    read(b);
    read(c);
}

#define pb push_back

#define all(x) x.begin(), x.end()

int n, m, tar;
bool judge(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;
    return true;
}

bool mp[85][85]; int ans = 0;
int d[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
void dfs(int x, int y, int k)
{
    
    if (y == m + 1)
    {
        y = 1; 
        ++x;
    }
    if (x == n + 1)
    {
        if (k == tar)
            ++ans;
        return;
    }
    
    dfs(x, y + 1, k);
    if (mp[x][y])
        return;

    bool flag = k < tar;
    for (int i = 0; flag && i < 4; ++i)
    {
        int dx = x + d[i][0], dy = y + d[i][1];
        if (judge(dx, dy) && mp[dx][dy])
            flag = false;
    }
    if (flag)
    {
        mp[x][y] = true;
        dfs(x, y + 1, k + 1);
        mp[x][y] = false;
    }
}

void solve()
{   
    read(n); read(m); read(tar);
    ans = 0;
    memset(mp, false, sizeof(mp));
    dfs(1, 1, 0);
    printf("%d\n", ans % 420047);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}