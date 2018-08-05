#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int N = 2e5 + 10;

set<int> S;
vector<int> ans;
priority_queue<pii, vector<pii>, greater<pii> > pq;

int n, h[N];

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int cnt = 0; ans.clear(); S.clear();
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", h + i);
            if (h[i] != -1)
                ++cnt;
            S.insert(i);
            if (h[i] % n == i)
                pq.push(mp(h[i], i));
        }
        while (!pq.empty())
        {
            pii t = pq.top();
            pq.pop();
            if (S.count(t.second) == 0)
                continue;
            ans.push_back(t.first);
            S.erase(t.second);
            if (S.empty())
                continue;
            set<int>::iterator it1 = S.upper_bound(t.second); 
            if (it1 == S.end())                           
                it1 = S.begin();
            if (h[*it1] == -1)
                continue;
            set<int>::iterator it2 = S.lower_bound(h[*it1] % n);
            if (it2 == S.end())
                it2 = S.begin();
            if (it1 == it2)
                pq.push(mp(h[*it1], *it1));
        }
        if (ans.size() == cnt)
            for (int i = 0; i < cnt; ++i)
                printf("%d ", ans[i]);
        else
            printf("-1");
        puts("");
    }
    return 0;
}