#include <iostream>
using namespace std;
const int maxn = 2 * 100005;
int n, q, a[maxn], sta[maxn], vis[maxn];
bool flag = true;
int main(void)
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0 && i)
            a[i] = a[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0 && i != n - 1)
            a[i] = a[i + 1];
    }
    if (a[0] == 0)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            cout << q << ' ';
        cout << endl;
    }
    else
    {
        int maxnum = 0;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            if (maxnum < a[i])
            {
                maxnum = a[i];
                if (vis[a[i]] == -1)
                {
                    flag = false;
                    break;
                }
                vis[a[i]] = 1;
                sta[p++] = a[i];
            }
            else if (maxnum > a[i])
            {
                while (p && sta[p - 1] > a[i])
                {
                    vis[sta[p - 1]] = -1;
                    p--;
                }
                if (p == 0 || sta[p - 1] < a[i])
                {
                    if (vis[a[i]] == -1)
                    {
                        flag = false;
                        break;
                    }
                    vis[a[i]] = 1;
                    sta[p++] = a[i];
                }
                maxnum = a[i];
            }
        }
        if (flag == false)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
                cout << a[i] << ' ';
            cout << endl;
        }
    }
}