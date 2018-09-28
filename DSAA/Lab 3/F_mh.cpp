#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q1;
priority_queue<int, vector<int>, less<int>> q2;
void add(int x)
{
    if (x > q1.top())
        q1.push(x);
    else
        q2.push(x);
    while (q1.size() < q2.size())
    {
        q1.push(q2.top());
        q2.pop();
    }
    while (q1.size() > q2.size() + 1)
    {
        q2.push(q1.top());
        q1.pop();
    }
}
void solve()
{
    while (!q1.empty())
        q1.pop();
    while (!q2.empty())
        q2.pop();
    int n;
    scanf("%d", &n);
    for (int i = 0, x; i < n; i++)
    {
        scanf("%d", &x);
        if (i == 0)
            q1.push(x);
        else
            add(x);
        if (i % 2 == 0)
            printf("%d ", q1.top());
    }
    puts("");
}
int main(void)
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}