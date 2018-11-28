#include <cstdio>
#include <cstring>
#include <vector>
const int N = 100000 + 10;
const int M = 25000 + 10;
using namespace std;
int a[N],b[M];
int n,m;
void Readin()
{
    int s;
    scanf("%d%d%d",&n,&m,&s);
    for (int i=1;i<=n;++i)
        scanf("%d",a + i);
    for (int i=1;i<=m;++i)
        scanf("%d",b + i);
}
vector<int> ans;
int as[N][30],bs[M][30];
void Pre()
{
    ans.clear();
    memset(as,0,sizeof(as));
    memset(bs,0,sizeof(bs));
    as[1][a[1]] = bs[1][b[1]] = 1;
    for (int i=2;i<=n;++i)
    {
        memcpy(as[i],as[i - 1],sizeof(as[0]));
        ++as[i][a[i]];
    }
    for (int i=2;i<=m;++i)
    {
        memcpy(bs[i],bs[i - 1],sizeof(bs[0]));
        ++bs[i][b[i]];
    }
}
int next[M];
void GetNext()
{
    memset(next,0,sizeof(next));
    next[1] = 0;
    int si,ei,sj,ej,k;
    int i=1,j=0;
    while (i <= m)
    {
        si = ei = sj = ej = 0;
        for (k=1;k<b[i];++k)
            si += bs[i][k] - bs[i - j][k];
        ei = bs[i][k] - bs[i - j][k];
        for (k=1;k<b[j];++k)
            sj += bs[j][k];
        ej = bs[j][k];
        if (j == 0 || (si == sj && ei == ej))
            i++,j++,next[i] = j;
        else
            j = next[j];
    }
}
void Kmp()
{
    int si,ei,sj,ej;
    int i = 1,j = 1,k;
    while (i <= n)
    {
        si = ei = sj = ej = 0;
        for (k=1;k<a[i];++k)
            si += as[i][k] - as[i - j][k];
        ei = as[i][k] - as[i - j][k];
        for (k=1;k<b[j];++k)
            sj += bs[j][k];
        ej = bs[j][k];
        if ((j == 0) || (si == sj && ei == ej))
            ++i,++j;
        else
            j = next[j];
        if (j == m + 1)
        {
            ans.push_back(i - m);
            j = next[j];
        }
    }
}
void Print()
{
    int cnt = ans.size();
    printf("%d\n",cnt);
    for (int i=0;i<cnt;++i)
        printf("%d\n",ans[i]);
}
int main()
{
    Readin();
    Pre();
    GetNext();
    Kmp();
    Print();
    return 0;
}
