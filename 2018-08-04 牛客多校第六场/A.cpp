#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = (1 << 14);
int n, s;
vector<int> vec[N];
int winner[N << 1];

int fight(int a, int b)
{
    int winner = vec[a].back() > vec[b].back() ? a : b;
    int loser = winner ^ a ^ b;
    auto it = upper_bound(vec[winner].begin(), vec[winner].end(), vec[loser].back());
    vec[winner].erase(it);
    return winner;
}
int solve()
{
    scanf("%d", &n);
    s = (1 << n);
    for (int i = 0; i < s; ++i)
    {
        vec[i].resize(n);
        for (int j = 0; j < n; ++j)
            scanf("%d", &vec[i][j]);
        sort(vec[i].begin(), vec[i].end());
    }
    for (int i = 0; i < s; ++i)
        winner[s + i] = i;
    for (int i = s - 1; i; --i)
        winner[i] = fight(winner[i << 1], winner[i << 1 | 1]);
    return winner[1] + 1;
}

int main()
{
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        printf("Case #%d: %d\n", i, solve());
    return 0;
}