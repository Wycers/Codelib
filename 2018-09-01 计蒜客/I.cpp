#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
const int C = 10;
const ll Mo = 1e9 + 7;
int tot[N], num[N], len[N], fail[N], S[N], ch[N][C], length[N];
ll POW[N], dig[N];
int p, last, cnt;
int newnode(int l)
{
    tot[p] = 0;
    num[p] = 0;
    len[p] = l;
    return p++;
}
void init()
{
    p = 0;
    memset(ch, 0, sizeof(ch));
    newnode(0);
    newnode(-1);
    last = 0;
    cnt = 0;
    S[cnt] = -1;
    fail[0] = 1;
}
int get_fail(int x)
{
    while (S[cnt - len[x] - 1] != S[cnt])
        x = fail[x];
    return x;
}
ll ans = 0;
void add(ll c, int pos)
{
    S[++cnt] = c;
    int cur = get_fail(last);
    if (!ch[cur][c])
    {
        int now = newnode(len[cur] + 2);
        fail[now] = ch[get_fail(fail[cur])][c];
        ch[cur][c] = now;
        if (cur == 1)
        {
            dig[now] = c;
            length[now] = 1;
        }
        else if (cur == 0)
        {
            dig[now] = c * 10 + c;
            length[now] = 2;
        }
        else {
            dig[now] = (1ll * c * POW[length[cur] + 1] % Mo + 1ll * dig[cur] * 10 % Mo + 1ll * c) % Mo;
            length[now] = length[cur] + 2;
        }
        ans += dig[now];
        ans %= Mo;
    }
    last = ch[cur][c];
    tot[last]++;
}
string str;
int main()
{
    POW[0] = 1;
    for (int i = 1; i <= 2000000; ++i)
        POW[i] = POW[i - 1] * 10 % Mo; 
    init();
    cin >> str;
    for (int i = 0, len = str.length(); i < len; ++i)
        add(str[i] - '0', i);
    printf("%lld\n", ans);
    return 0;
}