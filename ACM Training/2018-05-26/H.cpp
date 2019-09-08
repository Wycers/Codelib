#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    string str = "0";
    while (str.length() <= 100000)
    {
        for (int i = 0, t = str.length(); i < t; ++i)
            str += str[i] == '0' ? '1' : '0'; 
    }
    int T, x;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
    {
        scanf("%d", &x);
        cout << str.substr(0, x) << endl;
    }
    return 0;
}