#include <bits/stdc++.h>
using namespace std;
int n, m;
string str;
void solve()
{
    cin >> n >> str;
    m = n >> 1;
    for (int i_ = 0; i_ < m; ++i_)
    {
        int i = i_, j = n - i_ - 1;
        int t = str[i] - str[j];
        if (abs(t) == 0 || abs(t) == 2)
            continue;
        puts("NO");
        return;
    }
    puts("YES");
}
int main()
{
    freopen("test.in", "r", stdin);
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}