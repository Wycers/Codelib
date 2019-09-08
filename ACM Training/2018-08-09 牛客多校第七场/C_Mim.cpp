#include <cstdio>
#include <cstring>
#include <bitset>
#include <queue>
#include <iostream>
typedef long long ll;
const int N = 1 << 20 | 1;
using namespace std;

int n, m; ll ans = 0;
char str[N];

int limit, f[N];
bool judge(bool *str, int len)
{
    for (int i = 0; i < len; ++i)
        if (str[i] == 1)
            return true;
    return false;
}
void dfs(bool *str, int len)
{
    if (len == 1)
    {
        if (str[0] == 1)
            ++ans;
        return;
    }
    bool ss[N];
    for (int i = 0; i < len; i += 2)
        ss[i >> 1] = (str[i] | str[i + 1]);
    if (judge(ss, len >> 1))
        dfs(ss, len >> 1);

    for (int i = 0; i < len; i += 2)
        ss[i >> 1] = (str[i] & str[i + 1]);
    if (judge(ss, len >> 1))
        dfs(ss, len >> 1);

    for (int i = 0; i < len; i += 2)
        ss[i >> 1] = (str[i] ^ str[i + 1]);
    if (judge(ss, len >> 1))
        dfs(ss, len >> 1);
}  

queue<pair<int, int> > q;
void generate(int k, int w, int val, int now, int opt)
{
    if (k == 0)
    {   
        q.push(make_pair(now, w << 1));
        return;
    }
    int tag = (val & (1 << (k - 1)));
    if (opt == 0)
    {
        if (tag == 0)
        {
            generate(k - 1, w, val, now << 2 | 0, opt);
        }
        else
        {
            generate(k - 1, w, val, now << 2 | 1, opt);
            generate(k - 1, w, val, now << 2 | 2, opt);
            generate(k - 1, w, val, now << 2 | 3, opt);
        }
    }
    else  if (opt == 1)
    {
        if (tag == 0)
        {
            generate(k - 1, w, val, now << 2 | 0, opt);
            generate(k - 1, w, val, now << 2 | 1, opt);
            generate(k - 1, w, val, now << 2 | 2, opt);
        }
        else
        {
            generate(k - 1, w, val, now << 2 | 3, opt);
        }
    }
    else 
    {
        if (tag == 0)
        {
            generate(k - 1, w, val, now << 2 | 0, opt);
            generate(k - 1, w, val, now << 2 | 3, opt);
        }
        else
        {
            generate(k - 1, w, val, now << 2 | 1, opt);
            generate(k - 1, w, val, now << 2 | 2, opt);
        }
    }
} 
 
void bfs()
{ 
    while (!q.empty())
        q.pop();
    q.push(make_pair(1, 1));
    while (!q.empty())
    {
        pair<int, int> now = q.front(); q.pop();
        if (now.second == (1 << limit))
            ans += f[now.first];
        else
        {
            generate(now.second, now.second, now.first, 0, 0);
            generate(now.second, now.second, now.first, 0, 1);
            generate(now.second, now.second, now.first, 0, 2);
        }
    }
}

int main()
{
    string s;
    cin >> n >> s;
    bool str[N];
    for (int i = 0, len = s.length(); i < len; ++i)
        str[i] = (s[i] == '1');

    
    memset(f, 0, sizeof f);
    limit = min(n >> 1, 4);
    dfs(str, 1 << n);
    bfs();
    cout << ans << endl;
    return 0;
}