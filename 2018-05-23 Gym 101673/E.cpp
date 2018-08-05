#include <cstring>
#include <iostream>
#include <map>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 510;
int n, m;
bool ans[N][N][2];

struct edge_
{
    int to, next, type;
} edge[N * N];
int head[N], cnt = 0;
void insert(int u, int v, int t)
{
    edge[++cnt] = (edge_){v, head[u], t};
    head[u] = cnt;
}

static map<string, int> Vince;
inline int lanran(const string &s) {
    if (Vince.count(s))
        return Vince[s];
    Vince.insert(make_pair(s, Vince.size() + 1));
    return Vince[s];
}
map<string, int> mp; int tot = 0;


void readin()
{
    cin >> n >> m;
    string a, r, b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> r >> b;
        insert(lanran(a), lanran(b), r == "has-a");
    }
}

queue<pair<int, bool> > q;
void bfs(int s)
{ 
    while (!q.empty())
        q.pop();
    q.push(make_pair(s, 0));
    ans[s][s][0] = 1;
    while (!q.empty())
    {
        pair<int, bool> p = q.front(); q.pop();
        int now = p.first; bool nowt = p.second;
        for (int i = head[now]; i; i = edge[i].next)
        {
            int v = edge[i].to; bool vt = edge[i].type;
            if (vt == 0 && ans[s][v][nowt] == false)
            {
                ans[s][v][nowt] = true;
                q.push(make_pair(v, nowt));
            }
            if (vt == 1 && ans[s][v][1] == false)
            {
                ans[s][v][1] = true;
                q.push(make_pair(v, 1));
            }
        }
    }
}
void solve()
{
    for (int i = 1; i <= Vince.size(); ++i)
        bfs(i);
    string a, r, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> r >> b;
        printf("Query %d: %s\n", i, ans[lanran(a)][lanran(b)][r == "has-a"] ? "true" : "false"); 
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    readin();
    solve();
    return 0;
}