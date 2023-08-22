#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
// #define _DEBUG
const int N = 1e3 + 10;
int n, sp[N][N], tp[N][N];
map<string, int> s, t;
string sname[N];
void readin()
{
#ifdef _DEBUG
    freopen("test.in", "r", stdin);
#endif
    cin >> n;
    
    s.clear(), t.clear();
    string tmp; 
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        t[tmp] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        s[tmp] = i;
        sname[i] = tmp;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> tmp;
            tp[i][j] = s[tmp];
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> tmp;
            sp[i][j] = t[tmp];
        }
}
int now[N], match[N], rk[N][N], sb[N];
queue<int> q;
void solve()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            rk[i][sp[i][j]] = j;

    while (!q.empty())
        q.pop();
    memset(now, 0, sizeof now);
    memset(match, -1, sizeof match);
    for (int i = 0; i < n; ++i)
        q.push(i);
    while (!q.empty())
    {
        int p = q.front(); q.pop();
        int to = tp[p][now[p]++];
        if (match[to] == -1)
            match[to] = p;
        else if (rk[to][p] < rk[to][match[to]])
        {
            q.push(match[to]);
            match[to] = p;
        }
        else
            q.push(p);
    }
    for (int i = 0; i < n; ++i)
        sb[match[i]] = i;
    for (int i = 0; i < n; ++i)
        cout << sname[sb[i]] << " ";
}
int main()
{
    readin();
    solve();
    return 0;
}