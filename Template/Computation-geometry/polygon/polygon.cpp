#include "../line/line.cpp"
const int N = 1e5 + 10;
struct polygon 
{
    int n;
    Vector p[N];
    Line l[N];
    void input(int _n) {
        n = _n;
        for (int i = 0; i < n; ++i)
            p[i].input();
    }
    void add(Vector q) {
        p[n++] = q;
    }
    void generate() {
        for (int i = 0; i < n; ++i)
            l[i] = Line(p[i], p[(i + 1) % n]);
    }
    struct cmp {
        Vector p;
        cmp (const Vector &p0) { p = p0; };
        bool operator () (const Vector &a, const Vector &b) {
            int d = sign((a - p) ^ (b - p));
            if (d == 0)
                return sign(a.distance(p) - b.distance(p)) == -1;
            return d > 0;
        }
    };
    // 极角排序
    void norm() {
        Vector mi = p[0];
        for (int i = 1; i < n; ++i)
            mi = min(mi, p[i]);
        sort(p, p + n, cmp(mi));
    }
    // 判断凸性
    bool isconvex() {
        bool s[3] = {false, false, false};
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            int k = (j + 1) % n;
            s[sign((p[j] - p[i]) ^ (p[k] - p[i])) + 1] = true;
            if (s[0] && s[2])
                return false;
        }
        return true;
    }
    // 判断某点与该多边形的关系，3 - 点上，2 - 边上，1 - 内部，0 - 外部
    int relationpoint(const Vector &q) {
        for (int i = 0; i < n; i++)
            if (p[i] == q)
                return 3;
        generate();
        for (int i = 0; i < n; i++)
            if (l[i].cross(q))
                return 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int j = (i + 1) % n;
            int k = sign((q - p[j]) ^ (p[i] - p[j]));
            int u = sign(p[i].y - q.y);
            int v = sign(p[j].y - q.y);
            if (k > 0 && u < 0 && v >= 0)
                ++cnt;
            if (k < 0 && v < 0 && u >= 0)
                --cnt;
        }
        return cnt != 0;
    }
    // 求该多边形周长
    double circumference() {
        double res = 0;
        for (int i = 0; i < n; i++)
            res += p[i].distance(p[(i + 1) % n]);
        return res;
    }
    // 求该多边形面积
    double area() {
        double res = 0;
        for (int i = 0; i < n; i++)
            res += (p[i] ^ p[(i + 1) % n]);
        return fabs(res) / 2;
    }
};