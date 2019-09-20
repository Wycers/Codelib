#include <cstdio>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
int n, m;
string str[10], word;
bool solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> str[i];
        transform(str[i].begin(), str[i].end(), str[i].begin(), ::tolower);
    }
    cin >> m;
    bool flag = false;
    for (int i = 0; i < m; ++i)
    {
        cin >> word;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (flag)
            continue;
        for (int j = 0; j < n; ++j)
            if (word.compare(str[j]) == 0)
                flag = true;
    }
    return flag;
}
int main()
{
    int T; cin >> T;
    while (T--)
        cout << (solve() ? "Appeared" : "Not appeared");
    return 0;
}