#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, nn;
ll solve(ll x, ll y)
{
    ll t = (x + y) & 1, ans = 0;
    if (t == 0)
    {
        if (y & 1)
        {
            ans = (y - 1) / 2 + 1 + (x - 1) / 2 * n;
        }
        else
        {
            ans = (y / 2) + (x - 2) / 2 * n;
            if (n & 1)
                ans += (n + 1) / 2;
            else 
                ans += n / 2;
        }
    }
    else 
    {
        if (y & 1)
        {
            ans = (y + 1) / 2 + (x - 1) / 2 * n;
            if (n & 1)
                ans += (n - 1) / 2;
            else 
                ans += n / 2;
        }   
        else 
        {
            ans = (y / 2) + (x - 1) / 2 * n;
        }
        ans += nn;
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    ll x, y;
    nn = solve(n, n);
    while (m--)
    {
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
    return 0;
}