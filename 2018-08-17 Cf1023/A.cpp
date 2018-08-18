#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, m;
string a, b;
int main()
{
    scanf("%d%d", &n, &m);
    cin >> a >> b;
    bool flag = false;
    for (int i = 0; i < n; ++i)
        if (a[i] == '*')
            flag = true;
    if (n > m + flag)
    {
        puts("NO");
        return 0;
    }
    for (int i = 0; i < n; ++i)
        if (a[i] == '*')
        {
            if (n == m + 1)
                a.erase(i, 1);
            else   
                a.insert(i, string(m - n, '*'));
            break;
        }
    flag = true;
    for (int i = 0; i < m; ++i)
    {
        if (a[i] == '*' || a[i] == b[i])
            continue;
        flag = false;
    }
    puts(flag ? "YES" : "NO");
    return 0;
}