#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 2e5 + 10;
int n, enter[26], leave[26];
vector<int> v;

struct node
{
    int mn, lazy;
} tr[2000];

void pushdown(int k)
{
    if (tr[k].lazy)
    {
        tr[k << 1].mn += tr[k].lazy;
        tr[k << 1].lazy += tr[k].lazy;
        tr[k << 1 | 1].mn += tr[k].lazy;
        tr[k << 1 | 1].lazy += tr[k].lazy;
        tr[k].lazy = 0;
    }
}
void update(int k, int l, int r, int L, int R)
{
    if (l == L && r == R)
    {
        ++tr[k].mn;
        ++tr[k].lazy;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(k);
    if (L <= mid)
        update(k << 1, l, mid, L, min(mid, R));
    if (mid < R)
        update(k << 1 | 1, mid + 1, r, max(L, mid + 1), R);
    tr[k].mn = min(tr[k << 1].mn, tr[k << 1 | 1].mn);
}
int query(int k, int l, int r, int L, int R)
{
    if (l == L && r == R)
        return tr[k].mn;
    int mid = (l + r) >> 1, res = 0x3f3f3f3f;
    pushdown(k);
    if (L <= mid)
        res = min(res, query(k << 1, l, mid, L, min(mid, R)));
    if (mid < R)
        res = min(res, query(k << 1 | 1, mid + 1, r, max(L, mid + 1), R));
    return res;
}

void solve()
{
    memset(enter, -1, sizeof enter);
    memset(tr, 0, sizeof tr);
    v.clear();


    string str; cin >> str;
    for (int i = 0, len = str.length(); i < len; ++i)
    {
        int ch = str[i] - 'A';
        if (enter[ch] == -1)
        {
            enter[ch] = i + 1;
            v.push_back(ch);
        }
        else 
            leave[ch] = i + 1;
    }

    int ans = 0;
    for (int i = 0, len = v.size(); i < len; ++i)
    {
        if (query(1, 1, 52, enter[v[i]], leave[v[i]]) >= n)
            ++ans;
        update(1, 1, 52, enter[v[i]], leave[v[i]]);
    }
    printf("%d\n", ans);
}
int main()
{
    while (~scanf("%d", &n))
    {
        if (n == 0)
            break;
        solve();
    }
    return 0;
}