#include <iostream>
using namespace std;
int main()
{
    long long c, n, ans1, ans2;
    cin >> c >> n;
    if (c > n)
    {
        puts("-1");
        return 0;
    }
    n -= n % c;
    ans1 = c * c;
    ans2 = n * n - n * c;
    cout << (ans1 > ans2 ? ans1 : ans2);
    return 0;
}