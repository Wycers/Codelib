#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3e3 + 10;

int n, m, c[N], p[N], pos[N];
vector<int> vec[N];


int cnt(int i)
{
    return vec[i].size() - pos[i];
}
int getmax()
{
    int res = 0;
    for (int i = 2; i <= m; ++i)
        res = max(res, cnt(i));
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", p + i, c + i);
        vec[p[i]].push_back(c[i]);
    }
    for (int i = 1; i <= m; ++i)
        sort(vec[i].begin(), vec[i].end());
    memset(pos, 0, sizeof pos);
    int mx; long long ans = 0;
    while (vec[1].size() <= (mx = getmax()))
    {
        int min1 = 0x3f3f3f3f, min2 = 0x3f3f3f3f, tag1 = -1, tag2 = -1;
        for (int i = 2; i <= m; ++i)
            if (cnt(i))
            {
                if (vec[i][pos[i]] < min1)
                {
                    min2 = min1; tag2 = tag1;
                    min1 = vec[i][pos[i]]; tag1 = i;
                }
                else if (vec[i][pos[i]] < min2)
                {
                    min2 = vec[i][pos[i]]; tag2 = i;
                }
            }

        if (mx == vec[1].size())
        {
            ans += vec[tag1][pos[tag1]];
            vec[1].push_back(vec[tag1][pos[tag1]++]);
            continue;
        }
        long long sum = 0;
        sum += tag1 == -1 ? 0 : vec[tag1][pos[tag1]];
        sum += tag2 == -1 ? 0 : vec[tag2][pos[tag2]];
        int mn = 0x3f3f3f3f, tag = -1;
        for (int i = 2; i <= m; ++i)
            if (cnt(i) == mx)
                if (vec[i][pos[i]] < mn)
                {
                    mn = vec[i][pos[i]];
                    tag = i;
                }
        if (tag1 == -1 || sum >= 1ll * mn)
        {
            ans += vec[tag][pos[tag]];
            vec[1].push_back(vec[tag][pos[tag]++]);
        }
        else
        {
            ans += vec[tag1][pos[tag1]];
            vec[1].push_back(vec[tag1][pos[tag1]++]);
        }
    }
    cout << ans << endl;
    return 0;
}