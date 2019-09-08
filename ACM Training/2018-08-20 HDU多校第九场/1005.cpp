#include <bits/stdc++.h>
using namespace std;
namespace Quick_in {
    const int LEN=(1<<21)+1; char ibuf[LEN],*iH,*iT;int f,c;
#define gc() (iH==iT?(iT=(iH=ibuf)+fread(ibuf,1,LEN,stdin),(iH==iT?EOF:*iH++)):*iH++)
    inline char nc(){
        while((c=gc())<=32)if(c==-1)return -1;
        return (char)c;
    }
    template<class T> inline void sc(T&x) {
        for (f=1,c=gc();c<'0'||c>'9';c=gc()) if (c=='-') f=-1;
        for (x=0;c<='9'&&c>='0';c=gc()) x=x*10+(c&15); x*=f;
    }
    template<class T> inline bool read(T&x) {
        for (f=1,c=gc();c<'0'||c>'9';c=gc()){ if(c==-1)return 0;if(c=='-') f=-1; }
        for(x=c-48;;x=x*10+(c&15)){ if(!isdigit(c=gc()))break;}x*=f; return 1;
    }
    inline int gline(char*s) {
        int l=-1;
        for (c=gc();c<=32;c=gc())if(c==-1)return c;
        for (;c>32||c==' ';c=gc()){
            s[++l]=c;
        }
        s[l+1]=0;
        return l;
    }
    inline int gs(char *s) {
        int l=-1;
        for (c=gc();c<=32;c=gc())if(c==-1)return c;
        for (;c>32;c=gc()){
            s[++l]=c;
        }
        s[l+1]=0;
        return l;
    }
    template <typename A, typename B> inline void sc(A&x,B&y){sc(x),sc(y);};
    template <typename A, typename B> inline bool read(A&x,B&y){return read(x)&&read(y);};
}

using Quick_in::sc;
using Quick_in::read;
using Quick_in::gline;
using Quick_in::gs;
using Quick_in::nc;

namespace Quick_out {
    static const int BUFFER_MAX_SIZE = 1<<18;
    char buf[BUFFER_MAX_SIZE], *ph = buf, *pt = buf + BUFFER_MAX_SIZE;
    char tmp[100];
    const double dx[15] = {5e-1,5e-2,5e-3,5e-4,5e-5,5e-6,5e-7,5e-8,5e-9,5e-10,5e-11,5e-12,5e-13,5e-14,5e-15};
    inline void my_flush() {
        fwrite(buf, sizeof(char), ph - buf, stdout);
        ph = buf;
    }
    inline void oc(char c) {
        *(ph++) = c;
        if (ph == pt) my_flush();
    }
    inline void os(const char *s) {
        for (int i = 0; s[i]; ++i) oc(s[i]);
    }
    inline void os(const string&s) {
        os(s.c_str());
    }
    template<class T>
    inline void oi(T x, char ec = '\n') {
        if (x < 0) oc('-'), x = -x;
        int len = 0;
        if (!x) tmp[len++] = '0';
        for(;x;) tmp[len++] = x % 10 + '0', x /= 10;
        for(;len;)  oc(tmp[--len]);
        oc(ec);
    }
    inline void od(double x, int fix = 8, char bc = '\n') {
        x += dx[fix];
        if (x < 0) oc('-'), x = -x;
        oi((long long)x, '.');
        x -= (long long)x;
        for(;fix--;) {
            x *= 10;
            oc('0' + (int)x);
            x -= (int)x;
        }
        oc(bc);
    }
    struct Quick_{~Quick_(){my_flush();}}oooOoooOO;
}

using Quick_out::oi;
using Quick_out::oc;
using Quick_out::os;
using Quick_out::od;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int N = 210;

struct Vector
{
    double x, y;
    Vector () {}
    Vector (double _x, double _y) {
        x = _x;
        y = _y;
    }
    void init()
    {
        sc(x, y);
    }
} p[N], Nor[N], pos;

Vector operator+(const Vector &a, const Vector &b)
{
    return (Vector){a.x + b.x, a.y + b.y};
}
Vector operator-(const Vector &a, const Vector &b)
{
    return (Vector){a.x - b.x, a.y - b.y};
}
Vector operator*(const Vector &a, const double &k)
{
    return (Vector){a.x * k, a.y * k};
}
Vector operator/(const Vector &a, const double &k)
{
    return (Vector){a.x / k, a.y / k};
}
double operator*(const Vector &a, const Vector &b)
{
    return a.x * b.x + a.y * b.y;
}
double operator^(const Vector &a, const Vector &b)
{
    return a.x * b.y - a.y * b.x;
}
inline int sign(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x > 0 ? 1 : -1;
}
inline double Area2(Vector &a, Vector &b, Vector &c)
{
    Vector t1 = b - a;
    Vector t2 = c - a;
    return t1 ^ t2;
}
inline double dist(Vector &a, Vector &b)
{
    Vector t = b - a;
    return sqrt(t * t);
}
inline double len(Vector &a)
{
    return sqrt(a * a);
}
struct Line
{
    Vector p, v;
    Line() {}
    Line(Vector _p, Vector _v)
    {
        p = _p;
        v = _v;
    }
} L[N], l[N], b[N], d[N];
struct Arc
{
    double s, t;
    Vector o;
    Arc() {}
    Arc(double _s, double _t, Vector _o) 
    {
        s = _s;
        t = _t;
        o = _o;
    }
} arc[N];
int top, n, m; double r;
bool judge(Vector &p)
{
    for (int i = 1; i <= n; ++i)
    {
        if (sign(L[i].v ^ (p - L[i].p)) == 0)
            return false;
        if (sign(L[i].v ^ (p - L[i].p)) * sign(l[i].v ^ (p - l[i].p)) < 0 && sign(b[i].v ^ (p - b[i].p)) * sign(d[i].v ^ (p - d[i].p)) < 0)
            return false;
    }
    for (int i = 1; i <= top; ++i)
    {
        Vector t = (p - arc[i].o);
        if (len(t) > r)
            continue;
        double angle = atan2(t.y, t.x);
        if (sign(angle - arc[i].s) == 1 && sign(angle - arc[i].t) == -1)
            return false;
    }
    return true;
}
Vector ava[8000010]; int cnt = 0;
void solve()
{
    sc(n, m);
    sc(r);
    for (int i = 1; i <= n; ++i)
        p[i].init();
    p[n + 1] = p[1];
    for (int i = 1; i <= n; ++i)
    {
        L[i] = Line(p[i], p[i + 1] - p[i]);
        Nor[i] = (Vector){L[i].v.y, -L[i].v.x} / len(L[i].v);
        if (sign(L[i].v ^ Nor[i]) == -1)
            Nor[i] = Nor[i] * -1.0;
    }

    for (int i = 1; i <= n; ++i)
    {
        Vector pp = L[i].p + Nor[i] * r;
        l[i] = Line(pp, L[i].v);
        b[i] = Line(L[i    ].p, Nor[i]);
        d[i] = Line(L[i + 1].p, Nor[i]);
    }
    
    // 取弧
    top = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (sign(L[i].v ^ L[i + 1].v) >= 0)
            continue;
        double s = atan2(Nor[i    ].y, Nor[i    ].x);
        double t = atan2(Nor[i + 1].y, Nor[i + 1].x);
        if (s > t)
            swap(s, t);
        arc[++top] = Arc(s, t, L[i + 1].p);
    }

    cnt = 0; int t = 2e4;
    for (int i = 1; i <= n; ++i)
    {
        for (int d = 0; d <= t; ++d)
        {
            Vector now = l[i].p + l[i].v * (double)d / t;
            if (!judge(now))
                continue;
            ava[++cnt] = now;
        }
    }
    for (int i = 1; i <= top; ++i)
    {
        double length = arc[i].t - arc[i].s;
        for (int d = 0; d <= t; ++d)
        {
            double angle = arc[i].s + (double)d * length / t;
            Vector now = arc[i].o + (Vector){cos(angle), sin(angle)} * r;
            if (!judge(now))
                continue;
            ava[++cnt] = now;
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        pos.init();
        double ans = 1e9;
        for (int j = 1; j <= cnt; ++j)
            ans = min(ans, dist(ava[j], pos));
        oi((int)round(ans));
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    int T;
    sc(T);
    while (T--)
        solve();
    return 0;
}