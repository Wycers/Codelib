#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    srand(time(0));
    freopen("readin.in", "w", stdout);
    cout << 1 << endl;
    int n = 100000, m = 10000;
    cout << n << " " << m << endl;
    for (int i = 1; i <= n; ++i)
        printf("%d ", rand() % 100000);
    puts("");
    for (int i = 1; i <= m; ++i)
    {
        if (rand() & 1)
        {
            cout << "QUERY " << rand() % 100000 << endl;
        }
        else
        {
            cout << "MODIFY " << rand() % n + 1 << " " << rand() % 100000 << endl;
        }   
    }
    return 0;
}