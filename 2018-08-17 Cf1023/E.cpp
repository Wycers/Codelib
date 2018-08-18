#include <iostream>
#include <algorithm>
using namespace std;

int n;
bool check(int x, int y, int X, int Y)
{
    cout << "? " << x << " " << y << " " << X << " " << Y << "\n";
    fflush(stdout);

    string ans;
    cin >> ans;

    return (ans == "YES");
}

int main()
{
    cin >> n;
    int x = 1, y = 1;
    string ans = "";
    for (int i = 0; i < n - 1; ++i)
    {
        if (x != n && check(x + 1, y, n, n))
        {
            ++x;
            ans += 'D';
        }
        else
        {
            ++y;
            ans += 'R';
        }
    }

    int X = n, Y = n;
    string temp = "";
    for (int i = 0; i < n - 1; ++i)
    {
        if (Y != 1 && check(1, 1, X, Y - 1))
        {
            --Y;
            temp += "R";
        }
        else
        {
            --X;
            temp += 'D';
        }
    }
    reverse(temp.begin(), temp.end());
    cout << "! " << ans + temp << endl;
    fflush(stdout);

    return 0;
}