#include <cstdio>
#include <algorithm>
const int N = 100000 + 10;
const int M = 1000000 + 10;
using namespace std;
int Read()
{
    int x = 0;char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x;
}

int c[N],next[N],f[M],head[M],s[M],st[M];
int n,m,cnt = 0;
void Init()
{
    n = Read();m = Read();
    for (int i=1;i<=n;++i)
    {
        c[i] = Read();
        f[c[i]] = c[i];
        if (c[i] != c[i - 1])
            ++cnt;
        if (!head[c[i]])
            st[c[i]] = i;
        ++s[c[i]];next[i] = head[c[i]];
        head[c[i]] = i;
    }
}
void Solve(int x,int y)
{
    for (int i=head[x];i;i=next[i])
    {
        if (c[i + 1] == y) --cnt;
        if (c[i - 1] == y) --cnt;
    }
    for (int i=head[x];i;i=next[i])
        c[i] = y;
    next[st[x]] = head[y]; //
    head[y] = head[x];
    s[y] += s[x];
    head[x] = st[x] = s[x] = 0;
}
void Work()
{
    int opt,x,y;
    while (m--)
    {
        opt = Read();
        if (opt == 2)
            printf("%d\n",cnt);
        else
        {
            x = Read();y = Read();
            if (x == y) continue;
            if (s[f[x]] > s[f[y]])
                swap(f[x],f[y]);
            x = f[x];y = f[y];
            if (!s[x]) continue;
            Solve(x,y);
        }
    }
}
int main()
{
    Init();
    Work();
    return 0;
}
