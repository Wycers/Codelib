#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll n, k, mo;


ll pow(ll a, ll b)
{
    ll r = 1;
    for (a %= mo; b; b >>= 1, a = a * a % mo)
        if (b & 1)
            r = r * a % mo;
    return r;
}

long long ans = 0;

int main()
{
    cin >> n >> k >> mo;
    --n;
    ans = pow(2, n + 1);
    ans = ans 
    cout << ans << endl;
    return 0;
}