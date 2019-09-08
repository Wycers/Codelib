#include <cstdio>
#include <queue>
#include <assert.h>
#define LL long long
using namespace std;
const int N = 2e6;
int g[N]; bool win[N];

int top = 1 << 20;
void init()
{
    for (LL x = 0; x < top; ++x)  
    {  
        g[x] = (x * 487237 + 1011807) % top;
        int y = x;  
        int sum = 0;  
        while (y)
        {
            sum += y & 1;
            y >>= 1;
        }  
        win[x] = sum & 1;
    }  
}

queue<int> q[2];
void solve()
{
    int now, tag = 0, money;
    for (int i = 0; i < top; ++i)
        q[tag].push(i);
    scanf("%d", &now);
    while (true)
    {
        printf("1\n");
        fflush(stdout);
        scanf("%d", &money);
        bool wins = (money == now + 1);
        while (!q[tag].empty())
        {
            if (win[q[tag].front()] == wins)
                q[tag ^ 1].push(g[q[tag].front()]);
            q[tag].pop();
        }
        
        now = money; 
        tag ^= 1;
        if (q[tag].size() == 1 && win[q[tag].front()])
        {
            printf("%d\n", 200 - now);
            fflush(stdout);
            return;
        }
    }
}
int main()
{
    init();
    solve();
    return 0;
}