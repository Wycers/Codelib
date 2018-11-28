#include <cstdio>
#include <queue>
#include <cstring>
const int N = 100000 + 10;
using namespace std;
int s,t;
int f[N];bool inq[N];
queue<int> q;
bool Work(int now,int v)
{
    if (0 <= v && v <= N && f[now] + 1 < f[v])
    {
        f[v] = f[now] + 1;
        if (v == t)
            return true;
        if (!inq[v])
        {
            q.push(v);
            inq[v] = true;
        }
    }
    return false;
}
void Bfs()
{
    memset(f,0x3f,sizeof(f));
    memset(inq,false,sizeof(inq));
    int now,v;
    f[s] = 0;
    inq[s] = true;
    q.push(s);
    while (!q.empty())
    {
        now = q.front(); q.pop();
        if (Work(now,now << 1))
            break;
        if (Work(now,now + 1))
            break;
        if (Work(now,now - 1))
            break;
    }
    printf("%d\n",f[t]);
}
int main()
{
    scanf("%d%d",&s,&t);
    Bfs();
    return 0;
}
