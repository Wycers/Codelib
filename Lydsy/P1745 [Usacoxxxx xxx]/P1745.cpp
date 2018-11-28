#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
const int N = 1e4 + 10;
using namespace std;
int Read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x;
}
struct node
{
    int v,w;
    bool operator < (const node &a) const
    {
        return v < a.v;
    }
};
vector<node> v1[N],v2[N];
int num[2][N],n,c,k;
int Work(vector<node> v[],int* num)
{
    priority_queue<node> q;
    int res = 0,temp = 0,sz;
    node t;
    for (int i=1;i<=n;++i)
    {
        res += num[i];
        temp -= num[i];
        sz = v[i].size();
        for (int j=0;j<sz;++j)
        {
            temp += v[i][j].w;
            q.push(v[i][j]);
        }
        while (temp > c)
        {
            t = q.top(); q.pop();
            if (temp - t.w > c)
            {
                temp -= t.w;
                num[t.v] -= t.w;
            }
            else
            {
                num[t.v] -= (temp - c);
                t.w -= (temp - c);
                temp = c;
                q.push(t);
            }
        }
    }
    return res;
}
void Init()
{
    k = Read(),n = Read(),c = Read();
    int s,e,w;
    for (int i=0;i<=n;++i)
    {
        v1[i].clear();
        v2[i].clear();
    }
    for (int i=1;i<=k;++i)
    {
        s = Read(); e = Read(); w = Read();
        if (s < e)
        {
            num[0][e] += w;
            v1[s].push_back((node){e,w});
        }
        else
        {
            s = n - s + 1;e = n - e + 1;
            num[1][e] += w;
            v2[s].push_back((node){e,w});
        }
    }
}
void Solve()
{
    int ans = 0;
    ans += Work(v1,num[0]);
    ans += Work(v2,num[1]);
    printf("%d\n",ans);
}
int main()
{
    Init();
    Solve();
    return 0;
}
