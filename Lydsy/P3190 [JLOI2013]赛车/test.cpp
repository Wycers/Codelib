#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define MAX 10010  
#define INF 1e18  
using namespace std;  
#define max(a,b) ((a) > (b) ? (a):(b))  
#define min(a,b) ((a) < (b) ? (a):(b))  
   
struct Complex{  
    double pos,v;  
}src[MAX];  
   
struct Interval{  
    double l,r;  
       
    Interval(double _ = .0,double __ = .0):l(_),r(__) {}  
    bool Merge(const Interval &a) {  
        if(a.r < l)  return false;  
        if(a.l > r)  return false;  
        l = max(l,a.l);  
        r = min(r,a.r);  
        return true;  
    }  
};  
   
int cnt,ans[MAX];  
   
int main()  
{  
    cin >> cnt;  
    for(int i = 1; i <= cnt; ++i)  
        scanf("%lf",&src[i].pos);  
    for(int i = 1; i <= cnt; ++i)  
        scanf("%lf",&src[i].v);  
    for(int i = 1; i <= cnt; ++i) {  
        Interval now(.0,INF);  
        bool flag = true;  
        for(int j = 1; j <= cnt; ++j) {  
            if(i == j)  continue;  
            Interval temp;  
            if(src[i].v == src[j].v)  
                temp = src[i].pos >= src[j].pos ? Interval(-INF,INF):Interval(-INF,-INF);  
            else if(src[i].v > src[j].v)  
                temp = Interval((src[j].pos - src[i].pos) / (src[i].v - src[j].v),INF);  
            else  
                temp = Interval(-INF,(src[j].pos - src[i].pos) / (src[i].v - src[j].v));  
            if(!now.Merge(temp)) {  
                flag = false;  
                break;  
            }  
        }  
        if(flag)  
            ans[++ans[0]] = i;  
    }  
    printf("%d\n",ans[0]);  
    for(int i = 1; i < ans[0]; ++i)  
        printf("%d ",ans[i]);  
    if(ans[0])  
        printf("%d",ans[ans[0]]);  
    return 0;  
}
