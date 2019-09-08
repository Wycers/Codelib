#include <iostream>
using namespace std;
long long n, k, ans;
int main(void)
{
    cin >> n >> k;
    if (k == 1)
        ans = 0;
    else if (k <= n)
    {
        ans = (k - 1) / 2;
    }
    else
    {
        int t = (n << 1) - 1;
        if (k > t)
            ans = 0;
        else
            ans = (t + 2 - k) / 2;
    }
    cout << ans << endl;
    return 0;
}