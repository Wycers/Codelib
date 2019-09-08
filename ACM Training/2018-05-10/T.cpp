#include <iostream>
using namespace std;
int main()
{
    string a;
    while (cin >> a);
    int len = a.length();
    if (a[len - 2] == 'h')
        cout << "No";
    else
        cout << "Yes";
    return 0;
}