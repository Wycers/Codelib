#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const double eps = 1e-8;
const int N = 10;
struct Point
{
    double x, y;
    Point () {}
    Point (double _x, double _y)
    {
        x = _x;
        y = _y;
    }
};

struct Vector
{
    double x, y;
    Vector () {}
    Vector (double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    double operator * (const Vector &b) const {
        return x * b.x + y * b.y;
    }
    double operator ^ (const Vector &b) const {
        return x * b.y - y * b.x;
    }
};

Vector operator - (const Point &a, const Point &b) {
    return Vector(a.x - b.x, a.y - b.y);
}
Vector operator * (const double a, const Vector &b) 
{
    return Vector(a * b.x, a * b.y);
}
int n;
string str[2]; double d[2], l[2];
void readin()
{
    cin >> str[0] >> d[0] >> l[0];
    cin >> str[1] >> d[1] >> l[1];
}
double angle(double deg)
{
    return deg / 180 * 3.1415926;
}
string get(int n)
{
    double theta = angle(240 + d[n]);
    Vector v = l[n] * Vector(cos(theta), sin(theta));
    int cnt = 0;
    while (v.y < 0)
    {
        v.y += sqrt(3) / 2;
        ++cnt;
    }
    --cnt;
    string s1 = "A";
    string s2 = str[n];
    string temp = "";
    if (str[n] == "DB")
        temp = "CA";
    if (str[n] == "BC")
        temp = "DA";
    if (str[n] == "CD")
        temp = "BA";
    for (int i = 1; i <= 2; ++i)
        s1 = s1 + temp;
    for (int i = 1; i <= 2; ++i)
        s2 = s2 + str[n];
    if (cnt & 1)
        swap(s1, s2);
    
    double x0 = -(double)(cnt + 1) / 2;
    double y = v.y;
    double g = v.x - x0;
    g -= v.y / sqrt(3);
    int tag = -1;
    while (g > 2)
        g -= 2;
    if (g > (1 - 2 * y / sqrt(3)))
    {
        g -= (1 - 2 * y / sqrt(3));
        if (g > 2 * y / sqrt(3))
            g -= 2 * y / sqrt(3);
        else
            tag = 1;
    }
    else 
    {
        tag = 0;
    }
    
    if (tag == -1)
    {
        if (g > (1 - 2 * y / sqrt(3)))
        {
            g -= (1 - 2 * y / sqrt(3));
            if (g > 2 * y / sqrt(3))
                g -= 2 * y / sqrt(3);
            else
                tag = 3;
        }
        else 
        {
            tag = 2;
        }
    }
    string res = "";
    if (tag & 1)
    {
        int a = (tag - 1) / 2;
        res.push_back((char)s1[a]);
        res.push_back((char)s1[a + 1]);
        res.push_back((char)s2[a + 1]);
    }
    else 
    {
        int a = tag / 2;
        res.push_back((char)s2[a]);
        res.push_back((char)s2[a + 1]);
        res.push_back((char)s1[a]);
    }
    return res;
}
void solve()
{   
    string a = get(0);
    string b = get(1);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a == b)
        puts("YES");
    else
        puts("NO");
}

int main()
{
    readin();
    solve();
    return 0;
}