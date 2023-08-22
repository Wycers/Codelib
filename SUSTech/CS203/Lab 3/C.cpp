#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n, a[26], tr[30];
void add(int x, int val)
{
    for (int i = x; i <= 26; i += i & -i)
        tr[i] += val;
}
int find(int x)
{
    int res = 0;
    for (int i = x; i >= 1; i -= i & -i)
        res += tr[i];
    return res;
}
void solve()
{
    memset(a, -1, sizeof a);
    memset(tr, 0, sizeof tr);
    string str; cin >> str;
    int ans = 0, people = 0;
    for (int i = 0, len = str.length(); i < len; ++i)
    {
        int ch = str[i] - 'A';
        if (a[ch] == -1)
        {
            a[ch] = i;
            if (find(26) >= n)
                ++ans;
            else
                add(ch + 1, 1);
        }
        else 
        {
            if (find(ch + 1) - find(ch) == 1)
                add(ch + 1, -1);
        }
    }
    printf("%d\n", ans);
}
int main()
{
    while (~scanf("%d", &n))
    {
        if (n == 0)
            break;
        solve();
    }
    return 0;
}