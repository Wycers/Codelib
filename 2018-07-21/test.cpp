#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
const int maxn = 2005;
int a[maxn];
int f(int x){
    return x-a[x-1];
}
int main(){
    freopen("1.txt","w",stdout);
    a[1]=a[2]=1;
    for(int i = 3; i < maxn; i++)
        a[i]=a[f(i)]+a[f(i-1)];
    int tot = 0;
    for(int i = 1; i < maxn; i++)
    {
        if(a[i]!=a[i-1]){
            cout<<endl;
        }
        cout<<a[i]<<' ';
    }
    return 0;
}