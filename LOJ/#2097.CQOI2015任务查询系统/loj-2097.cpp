//=============================================================
// File Name: loj-2097.cpp
// Author: Wycer
// Created Time: 2018-05-07 22:36
//=============================================================
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
const int N = 1e5 + 10;
using namespace std;
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
int n, m, s[N], e[N], p[N];
void readin()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
    {
        s[i] = read();
        e[i] = read();
        if (s[i] > e[i])
            swap(s[i], e[i]);
        p[i] = read();
    }
}

struct node
{
    int l, r, cnt;
    long long sum;
    node()
    {
        l = r = cnt = sum = 0;
    }
} tr[40 * N];
int cnt = 0;

void insert(int &k, int l, int r, int pos, int x)
{
    // tr[k = ++cnt] = tr[k];
    tr[++cnt] = tr[k];
    k = cnt;
    if (x > 0)
        ++tr[k].cnt;
    else
        --tr[k].cnt;
    tr[k].sum += x;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        insert(tr[k].l, l, mid, pos, x);
    else
        insert(tr[k].r, mid + 1, r, pos, x);
}

long long query(int k, int l, int r, int x)
{
    if (l == r)
        return tr[k].sum;
    int mid = (l + r) >> 1;
    int tmp = tr[tr[k].l].cnt;
    if (x <= tmp)
        return query(tr[k].l, l, mid, x);
    else
        return tr[tr[k].l].sum + query(tr[k].r, mid + 1, r, x - tmp);
}

int tag[N], r[N], root[N];
bool cmp(int a, int b)
{
    return p[a] < p[b];
}
bool cmp2(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first < b.first;
}

vector<pair<int, int>> vec;
void prework()
{
    for (int i = 1; i <= n; ++i)
        tag[i] = i;
    sort(tag + 1, tag + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
        r[tag[i]] = i;

    for (int i = 1; i <= n; ++i)
    {
        vec.push_back(make_pair(s[i], r[i]));
        vec.push_back(make_pair(e[i] + 1, -r[i]));
    }
    sort(vec.begin(), vec.end(), cmp2);

    vector<pair<int, int>>::iterator it = vec.begin();
    for (int i = 1; i <= m; ++i)
    {
        root[i] = root[i - 1];
        while (it != vec.end() && i == it->first)
        {
            if (it->second > 0)
                insert(root[i], 1, m, it->second, p[tag[it->second]]);
            else
                insert(root[i], 1, m, -it->second, -p[tag[-it->second]]);
            ++it;
        }
    }
}

void solve()
{
    int k, x, a, b, c;
    long long pre = 1;
    for (int i = 1; i <= m; ++i)
    {
        x = read();
        a = read();
        b = read();
        c = read();
        k = 1 + (a * pre + b) % c;
        printf("%lld\n", pre = query(root[x], 1, m, k));
    }
}

int main()
{
    readin();
    prework();
    solve();
    return 0;
}