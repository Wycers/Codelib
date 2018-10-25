#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}
int n, m, q;
struct opt1
{
    int r, cs, ct;
    opt1 () {}
    void init (int _r, int _cs, int _ct)
    {
        r = _r;
        cs = _cs;
        ct = _ct;
    }
};
struct opt2
{
    int c, rs, rt;
    opt2 () {}
    void init (int _c, int _rs, int _rt)
    {
        c = _c;
        rs = _rs;
        rt = _rt;
    }
};
inline bool cmp1(const opt1 &a, const opt1 &b)
{
    return a.r < b.r;
}
inline bool cmp2(const opt2 &a, const opt2 &b)
{
    return a.rs < b.rs;
}
vector<opt1> op1; int top1;
vector<opt2> op2; int top2;

struct cmp {
    bool operator()(const int &a, const int &b) {return op2[a].rt > op2[b].rt;}
};
priority_queue<int, vector<int>, cmp> ed;

int fa[N];
inline int getfa(int x)
{
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
struct tr
{
    int tr[N], tag[N];
    void add(int t, int pos, int x)
    {
        tag[pos] = t;
        for (int i = pos; i <= 1e5; i += i & -i)
            tr[i] += x;
    }
    int get(int pos)
    {
        int res = 0;
        for (int i = pos; i >= 1; i -= i & -i)
            res += tr[i];
        return res;
    }
    int at(int pos)
    {
        return get(pos) - get(pos - 1);
    }
} tr, tr2;
void solve()
{
    n = read(); m = read(); q = read();
    op1.clear(); op2.clear();
    while (!ed.empty())
        ed.pop();
    int r1, c1, r2, c2;
    for (int i = 1; i <= q; ++i)
    {
        fa[i] = i;
        r1 = read(); c1 = read(); r2 = read(); c2 = read();
        if (r1 == r2)
        {
            if (c1 > c2)
                swap(c1, c2);
            opt1 t; t.init(r1, c1, c2);
            op1.push_back(t);
        }
        else 
        {
            if (r1 > r2)
                swap(r1, r2);
            opt2 t; t.init(c1, r1, r2);
            op2.push_back(t);
        }
    }
    sort(op1.begin(), op1.end(), cmp1);
    sort(op2.begin(), op2.end(), cmp2);
    long long s = 0, block = 0;
    top1 = top2 = 0;
    for (int i = 1; i <= n; ++i)
    {  
        while (ed.size() && op2[ed.top()].rt < i)          // 移除列
        {
            int tag = ed.top();
            tr.add(tag, op2[tag].c, -1);
            ed.pop();
        }
        while (top1 < op1.size() && op1[top1].r == i)     // 添加行
        {
            s += op1[top1].ct - op1[top1].cs + 1;
            bool flag = true;
            int pos = op1[top1].cs - 1;
            if (1 <= pos)
            {
                if (tr.at(pos))
                {
                    flag = false;
                    int fx = getfa(tr.tag[pos]);
                    int fy = getfa(top1);
                    fa[fx] = fy;
                }
            }
            pos = op1[top1].ct + 1;
            if (pos <= m)
            {
                if (tr.at(pos))
                {
                    flag = false;
                    int fx = getfa(tr.tag[pos]);
                    int fy = getfa(top1);
                    fa[fx] = fy;
                }
            }
            block += flag;
            ++top1;
        }
        while (top2 < op2.size() && op2[top2].rs == i)    // 添加列
        {
            ed.push(top2);
            tr.add(top2, op2[top2].c, 1);
            ++top2;
        }
        s += ed.size();
        printf("%lld %lld\n", s, block);
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    for (int T = read(); T; --T)
        solve();
    return 0;
}