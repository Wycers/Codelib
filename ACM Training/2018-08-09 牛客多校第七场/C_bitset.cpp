#include <set>
#include <cstring>
#include <bitset>
#include <iostream>
const int N = 1 << 18 | 1;
using namespace std;
 
int n, m; long long ans = 0;
void dfs(bitset<N> &bs, int len)
{
    if (len == 1)
    {
        if (bs[0] == 1)
            ++ans;
        return;
    }
    bitset<N> nb;
    nb.reset();
    for (int i = 0; i < len; i += 2)
        nb.set(i >> 1, (bs[i]) | (bs[i + 1]));
    if (nb.any())
        dfs(nb, len >> 1);
 
    nb.reset();
    for (int i = 0; i < len; i += 2)
        nb.set(i >> 1, bs[i] & bs[i + 1]);
    if (nb.any())
        dfs(nb, len >> 1);
 
       nb.reset();
    for (int i = 0; i < len; i += 2)
        nb.set(i >> 1, bs[i] ^ bs[i + 1]);
    if (nb.any())
        dfs(nb, len >> 1);
}  
 
int main()
{
    string s;
    cin >> n >> s;
    bitset<N> bs(s);
    dfs(bs, 1 << n);
    cout << ans << endl;
    return 0;
}

// 裸bitset会超时。