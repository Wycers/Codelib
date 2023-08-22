#include <cstdio>
#include <iostream>
using namespace std;
const long long Mo = 1e9 + 7;
long long f[1005];
int main()
{
    int T;
    f[0] = 0;
    for (int i = 1; i <= 1000; ++i)
        f[i] = (f[i - 1] * 3 + 2) % Mo;
    cin >> T;
    while (T--)
    {
        int x;
        cin >> x;
        cout << f[x] << endl;
    }
    return 0;
}