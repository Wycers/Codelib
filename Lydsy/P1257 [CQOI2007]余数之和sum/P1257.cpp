#include <iostream>
using namespace std;
typedef long long ll;
int main()
{ 
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int a = k / i, l = k / (a + 1) + 1, r = a ? k / a : n;
		r = min(r, n);
		ans += (ll)k * (r - l + 1) - (ll)a * (l + r) * (r - l + 1) / 2;
		i = r; 
	}
	cout << ans << endl;
	return 0;
}
