#include <cstdio>
#include <cmath>
const int N = 200000 + 10;
using namespace std;
int n,m,block,cnt;
int pt[N],st[N],a[N],belong[N];
int Read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}
void Readin()
{
    n = Read();
    for (int i=1;i<=n;++i)
        a[i] = Read();
}

int l[1500],r[1500];
void Init()
{
    block = sqrt(n);
    cnt = n / block;
	if(n % block)
        ++cnt;
	for (int i=1;i<=cnt;++i)
	    l[i] = (i - 1) * block + 1,r[i] = i * block;
    r[cnt] = n;
    for (int i=1;i<=n;++i)
        belong[i] = (i - 1) / block + 1;
    for (int i=n;i>=1;--i)
    {
        if (i + a[i] > n)
            st[i] = 1;
        else if (belong[i] == belong[i + a[i]])
            st[i] = st[i + a[i]] + 1,pt[i] = pt[i + a[i]];
        else
            st[i] = 1,pt[i] = i + a[i];
    }
}

int Cal(int x)
{
    int temp = st[x];
    while (pt[x])
    {
        x = pt[x];
        temp += st[x];
    }
    return temp;
}

void Work()
{
    int m = Read(),opt,x,y;
    while (m--)
    {
        opt = Read();x = Read() + 1;
        if (opt == 1)
            printf("%d\n",Cal(x));
        else
        {
            y = Read();
            a[x] = y;
            for (int i=x;i>=l[belong[x]];--i)
                if (belong[i] == belong[i + a[i]])
                    st[i] = st[i + a[i]] + 1,pt[i] = pt[i + a[i]];
                else
                    st[i] = 1,pt[i] = i + a[i];
        }
    }
}
int main()
{
    Readin();
    Init();
    Work();
    return 0;
}
