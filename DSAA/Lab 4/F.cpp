#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100;
const int Ha = 1000000007;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
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
inline void add(long long &x, long long val)
{
    x += val;
    if (x >= Ha)
        x -= Ha;
}
inline void sub(long long &x, long long val)
{
    x -= val;
    if (x < 0)
        x += Ha;
}
inline long long mul(const long long &x, const long long &y)
{
    return x * y % Ha;
}
int n, m;
struct Mat
{
    long long mat[N][N];
    Mat () {
        memset(mat, 0, sizeof mat);
    }
    void input()
    {
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j)
                mat[i][j] = read();
    }
    void output()
    {
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j)
                printf("%lld%c", mat[i][j], j == m ? '\n' : ' ');
    }
    Mat operator + (const Mat &b) const {
        Mat c;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j)
            {
                add(c.mat[i][j],   mat[i][j]);
                add(c.mat[i][j], b.mat[i][j]);
            }
        return c;
    }
    Mat operator - (const Mat &b) const {
        Mat c;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j)
            {
                add(c.mat[i][j],   mat[i][j]);
                sub(c.mat[i][j], b.mat[i][j]);
            }
        return c;
    }
    Mat operator * (const Mat &b) const {
        Mat c;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j)
                for (int k = 1; k <= m; ++k)
                    add(c.mat[i][j], mul(mat[i][k], b.mat[k][j]));
        return c;
    }
} mt[15];
char str[100];
Mat work(int l, int r)
{
    vector<Mat> mat;
    vector<char> opt; 
    mat.clear(); opt.clear();
    for (int i = l; i < r; ++i)
    {
        if (str[i] == '(')
        {
            int cnt = 0;
            for (int j = i; j < r; ++j)
            {
                if (str[j] == '(')
                    ++cnt;
                if (str[j] == ')')
                {
                    if (--cnt > 0)
                        continue;
                    mat.push_back(work(i + 1, j));
                    if (opt.size() && opt.back() == '*')
                    {
                        Mat y = mat.back(); mat.pop_back();
                        Mat x = mat.back(); mat.pop_back();
                        opt.pop_back();
                        mat.push_back(x * y);
                    }
                    i = j;
                    break;
                }  
            }
                 
        }
        else
        {
            if ('1' <= str[i] && str[i] <= '9')
            {
                if (str[i + 1] == '0')
                {
                    mat.push_back(mt[10]);
                    ++i;
                }
                else
                    mat.push_back(mt[str[i] - '0']);
                if (opt.size() && opt.back() == '*')
                {
                    Mat y = mat.back(); mat.pop_back();
                    Mat x = mat.back(); mat.pop_back();
                    opt.pop_back();
                    mat.push_back(x * y);
                }
            }
            else 
                opt.push_back(str[i]);
        }
    }
    Mat res = mat[0];
    for (int i = 0, len = opt.size(); i < len; ++i)
    {
        if (opt[i] == '+')
            res = res + mat[i + 1];
        else 
            res = res - mat[i + 1];
    }
    return res;
}
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        mt[i].input();
    scanf("%s", str);
    Mat res = work(0, strlen(str));
    res.output();
}
int main()
{
    int T = read();
    while (T--)
        solve();
    return 0;
}