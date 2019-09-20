#include <cstdio>
#include<iostream>
#include<ctime>
#include <algorithm>
#include <cstring>
#include<cstdlib>
#include <queue>
using namespace std;
const int N = 2e5 + 10;
struct node
{
    int l, r;
} tr[N];
int fa[N], tag[N], rev[N];
int n;
queue<int> q;
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void go()
{
    printf("%d\n", n);
    while (!q.empty())
        q.pop();
    memset(tr, 0, sizeof tr);
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    int root = rand() % n + 1;
    q.push(root);
    for (int i = 1; i <= n; ++i)
    {
        if (i == root)
            continue;
        while (true)
        {
            int x = q.front(); q.pop();
            if (rand() & 1)
            {
                q.push(x);
                continue;
            }
        
            int fx = find(x);
            int fy = find(i);
            if (fx != fy)
            {
                fa[fx] = fy;
                
                if (tr[x].l + tr[x].r)
                {
                    if (tr[x].l)
                        tr[x].r = i;
                    else
                        tr[x].l = i;
                }
                else
                {
                    if (rand() & 1) 
                        tr[x].r = i;
                    else
                        tr[x].l = i;
                    q.push(x);
                }
                break;
            }
        }
        q.push(i);
    }
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", tr[i].l, tr[i].r);
}
int main()
{
    srand(time(0));
	int T = 2;
    printf("%d\n", T);
    for (int t = 1; t <= T; ++t)
    {
        n = rand() % 40000 + 1;
        printf("%d\n", n);
        for (int i = 1; i <= n; ++i)
            printf("%d ", rand() % 50 + 1);
        puts("");
        for (int i = 1; i <= n; ++i)
            printf("%d %d\n", rand() % n + 1, rand() % 50 + 1);
    }
    puts("");
    return 0;
}