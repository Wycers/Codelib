#include <iostream>
using namespace std;
long long n, p2, p3;
long long min(long long x, long long y)
{
    return x < y ? x : y;
}
int main()
{
    cin >> n >> p2 >> p3;
    long long ans = 1e18;
    for (int i = 0; i <= 3 && (n - i * 2 >= 0); i++)
        ans = min(ans, ((n - i * 2 + 2) / 3) * p3 + i * p2);
    for (int i = 0; i <= 3 && (n - i * 3 >= 0); i++)
        ans = min(ans, ((n - i * 3 + 1) / 2) * p2 + i * p3);
    cout << ans << endl;
    return 0;
}