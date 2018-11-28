#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct map_
{
    int a[5],k;
} sc,ta;
bool hash[16][16][16][16];
int pow[5],ans;
  
int Get()
{
    char ch = getchar();
    while (ch != '0' && ch != '1') ch = getchar();
    return ch - 48;
}
void Readin()
{
    pow[1] = 1;
    for (int i=2;i<=4;i++)
        pow[i] = pow[i - 1] * 2;
    for (int i=1;i<=4;i++)
    {
        sc.a[i] = 0;
        for (int j=4;j>=1;j--)
            sc.a[i] += pow[j] * Get();
    }
    sc.k = 0;
    for (int i=1;i<=4;i++)
    {
        ta.a[i] = 0;
        for (int j=4;j>=1;j--)
            ta.a[i] += pow[j] * Get();
    }
}
bool Judge(map_ a)
{
    for (int i=1;i<=4;i++)
        if (a.a[i] != ta.a[i])
            return false;
    return true;
}
bool update(map_ a)
{
    bool temp = hash[a.a[1]][a.a[2]][a.a[3]][a.a[4]];
    hash[a.a[1]][a.a[2]][a.a[3]][a.a[4]] = true;
    return temp;
}
  
bool RJudge(map_ a,int x,int y)
{
    y = 5 - y;
    return (((a.a[x] & pow[y]) > 0) != ((a.a[x] & pow[y - 1]) > 0));
}
bool DJudge(map_ a,int x,int y)
{
    y = 5 - y;
    return (((a.a[x] & pow[y]) > 0) != ((a.a[x + 1] & pow[y]) > 0));
}
map_ Rswap(map_ a,int x,int y)
{
    y = 5 - y;
    if ((a.a[x] & pow[y]) > 0)
        a.a[x] -= pow[y - 1];
    else
        a.a[x] += pow[y - 1];
    return a;
}
map_ Dswap(map_ a,int x,int y)
{
    y = 5 - y;
    if ((a.a[x] & pow[y]) > 0)
    {
        a.a[x] -= pow[y];
        a.a[x + 1] += pow[y];
    }
    else
    {
        a.a[x] += pow[y];
        a.a[x + 1] -= pow[y];
    }
    return a;
}
  
queue<map_> q;
void Bfs()
{
    memset(hash,false,sizeof(hash));
    q.push(sc);
    update(sc);
    ans = 0;
    if (Judge(sc))
        return;
    while (!q.empty())
    {
        map_ now = q.front(); q.pop();
        for (int i=1;i<=4;i++)
            for (int j=1;j<=4;j++)
            {
                if (i <= 3 && DJudge(now,i,j))
                {
                    map_ New = Dswap(now,i,j);
                    if (update(New))
                        continue;
                    New.k = now.k + 1;
                    q.push(New);
                    if (Judge(New))
                    {
                        ans = New.k;
                        return;
                    }
                }
                if (j <= 3 && RJudge(now,i,j))
                {
                    map_ New = Rswap(now,i,j);
                    New.k = now.k + 1;
                    if (update(New))
                        continue;
                    New.k = now.k + 1;
                    q.push(New);
                    if (Judge(New))
                    {
                        ans = New.k;
                        return;
                    }
                }
            }
    }
}
  
int main()
{
    Readin();
    Bfs();
    printf("%d\n",ans);
    return 0;
}
