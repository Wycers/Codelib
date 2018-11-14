#include <cstdio>
const int N = 100000 + 10;
using namespace std;
int a[N];
int n,m;
void Read(int &x)
{
    x = 0;char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
}
void Readin()
{
    Read(n);Read(m);
    for (int i=1;i<=n;++i)
        Read(a[i]);
}
bool Try(int x)
{
    int sum = 0,cnt = 1;
    for (int i=1;i<=n;++i)
    {
        if (a[i] > x)  //x too small
            return false;
        if (sum + a[i] <= x)
            sum += a[i];
        else
        {
            sum = a[i];
            if (++cnt > m) //x too small
                return false;
        }
    }
    return true; //x too large or equal
}

void Work()
{
    int l = 1,r = 0x3f3f3f3f,mid,now;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (Try(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%d\n",l);
}
int main()
{
    Readin();
    Work();
    return 0;
}
