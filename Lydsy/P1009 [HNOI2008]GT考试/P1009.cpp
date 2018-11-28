#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;
struct mxt
{
  int a[30][30];
}ans, be;
int n, m, inf, f[30];
string s;
mxt operator*(mxt a, mxt b)
{
  mxt t;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++)
    {
      t.a[i][j] = 0;
      for (int k = 0; k < m; k++)
        t.a[i][j] = (t.a[i][j] + (a.a[k][j] * b.a[i][k]) % inf) % inf;
    }
  return t;
}
mxt pw(int p)
{
  mxt a;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++)
      if (i == j) a.a[i][j] = 1;
      else a.a[i][j] = 0;
  while (p)
  {
    if (p & 1) a = a * ans;
    ans = ans * ans;
    p /= 2;
  }
  return a;
}
int main()
{
  cin >> n >> m >> inf >> s;
  int j = -1;
  f[0] = -1;
  for (int i = 1; i < m; i++)
  {
    while (j != -1 && s[j + 1] != s[i]) j = f[j];
    if (s[j + 1] == s[i]) j++;
    f[i] = j;
  }
  ans.a[0][0] = 9;
  ans.a[1][0] = 1;
  for (int i = 0; i < m; i++)
    for (char j = '0'; j <= '9'; j++)
    {
      int k = i;
      while (k != -1 && s[k + 1] != j) k = f[k];
      if (s[k + 1] == j) ans.a[k + 2][i + 1] = (ans.a[k + 2][i + 1] + 1) % inf;
      else ans.a[0][i + 1] = (ans.a[0][i + 1] + 1) % inf;
    }
  ans = pw(n);
  int as = 0;
  for (int i = 0; i < m; i++) as = (as + ans.a[i][0]) % inf;
	printf("%d\n", as);
	return 0;
}
