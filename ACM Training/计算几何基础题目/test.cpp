#include <iostream>  
#include <cstring>  
#include <algorithm>  
#include <cstdio>  
using namespace std;  
  
struct Point  
{  
    double x,y;  
};  
struct Segment  
{  
    Point p1,p2;  
};  
  
double cross(const Point& o,const Point & a,const Point& b)  
{  
    return (a.x - o.x)*(b.y-o.y) - (a.y - o.y)* (b.x - o.x);  
}  
  
double dot(const Point& o,const Point & a,const Point& b)  
{  
    return (a.x - o.x) * (b.x - o.x) + (a.y-o.y) * (b.y - o.y);  
}  
  
const double eps = 1E-8;  
int sig(double d)  
{  
    return (d > eps) - (d < -eps);  
}  
  
int btw(const Point& x,const Point& a,const Point&b)  
{  
    return sig(dot(x,a,b));  
}  
  
int SegCross(const Point & a,const Point & b,const Point& c,const Point& d)  
{  
    int d1,d2,d3,d4;  
    d1 = sig(cross(a,b,c));  
    d2 = sig(cross(a,b,d));  
    d3 = sig(cross(c,d,a));  
    d4 = sig(cross(c,d,b));  
    if((d1^d2)==-2&&(d3^d4)==-2)  
    {  
        return 1;  
  
    }  
    if(d1 == 0 && btw(c,a,b)<=0||  
            d2 == 0 && btw(d,a,b)<=0 ||  
            d3 == 0 && btw(a,c,d)<=0 ||  
            d4 == 0 && btw(b,c,d) <=0)  
        return 2;  
    return 0;  
}  
  
Segment seg[35];  
int n;  
  
int Test(const Segment& tseg)  
{  
  
    int cnt = 0;  
    for(int i = 0; i < n; i++)  
    {  
        if(SegCross(tseg.p1,tseg.p2,seg[i].p1,seg[i].p2)==1)  
            cnt ++;  
  
    }  
    return cnt;  
}  
  
  
int main()  
{  
  
    while(cin >> n)  
    {  
        Segment tseg;  
        for(int i = 0; i < n; i++)  
        {  
            scanf("%lf%lf%lf%lf",&seg[i].p1.x,&seg[i].p1.y,&seg[i].p2.x,&seg[i].p2.y);  
        }  
        cin >> tseg.p1.x;  
        cin >> tseg.p1.y;  
        int min = 100000;  
        int temp;  
  
        for(int i = 0; i < n; i++)  
        {  
            tseg.p2.x = seg[i].p1.x;  
            tseg.p2.y = seg[i].p1.y;  
            temp = Test(tseg);  
            if(temp < min)  
                min = temp;  
  
            tseg.p2.x = seg[i].p2.x;  
            tseg.p2.y = seg[i].p2.y;  
            temp = Test(tseg);  
            if(temp < min)  
                min = temp;  
        }  
        tseg.p2.x = 0;  
        tseg.p2.y = 0;  
        temp = Test(tseg);  
        if(temp < min)  
            min = temp;  
  
        tseg.p2.x = 0;  
        tseg.p2.y = 100;  
        temp = Test(tseg);  
        if(temp < min)  
            min = temp;  
  
        tseg.p2.x = 100;  
        tseg.p2.y = 0;  
        temp = Test(tseg);  
        if(temp < min)  
            min = temp;  
  
        tseg.p2.x = 100;  
        tseg.p2.y = 100;  
        temp = Test(tseg);  
        if(temp < min)  
            min = temp;  
  
        cout << "Number of doors = " << min + 1 << endl;  
  
    }  
  
  
  
  
    return 0;  
}