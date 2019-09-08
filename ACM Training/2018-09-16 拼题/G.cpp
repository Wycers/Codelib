
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
#define maxn 160000
using namespace std;
int read()
{
	char ch = getchar(); int x = 0, f = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
 
int lowbit(int x) {return x & -x;}
int n, m, top, s[maxn], root[maxn], rk[maxn];
long long ans;
 
struct tree {
	int l, r, sum;
	tree() : l(0), r(0), sum(0) {} 
}t[maxn * 60];
 
int getans(int x)
{
	int sum = 0;
	for(int i = x; i; i -= lowbit(i)) sum += s[i];
	return sum;
}
 
int update(int x) {
	for(int i = x;i <= n; i += lowbit(i)) ++s[i];
}
 
void add_tree(int &cur_p, int pos, int add, int L, int R)
{
	if(!cur_p) cur_p = ++top;
	t[cur_p].sum += add;
	if(L == R) return;
	int mid = L + R >> 1;
	if(pos <= mid) add_tree(t[cur_p].l, pos, add, L, mid);
	else add_tree(t[cur_p].r, pos, add, mid + 1, R);
}
 
void creat_tree(int p, int pos, int add) 
{
	for(int i = p;i <= n; i += lowbit(i)) 
        add_tree(root[i], pos, add, 1, n);
}
 
void init()
{
	n = read(); m = n;
	for(int i = 1;i <= n; ++i)
	{
		int a = read();
		rk[a] = i;
		ans += getans(n) - getans(a);
		update(a);
		creat_tree(i, a, 1);
	}
}
 
int get_sum(int p, int pos, int L, int R)
{
	if(L == R) return t[p].sum;
	int mid = L + R >> 1;
	if(pos <= mid) return get_sum(t[p].l, pos, L, mid);
	else return t[t[p].l].sum + get_sum(t[p].r, pos, mid + 1, R);
}
 
int query(int p, int pos) {
	int sum = 0;
	for(int i = p; i; i -= lowbit(i)) sum += get_sum(root[i], pos, 1, n);
	return sum;
}
 
int ask_prefix(int x, int pos) {
	return query(pos, n) - query(pos, x);
}
 
int ask_suffix(int x, int pos) {
	return query(n, x) - query(pos, x);
}
 
void solve()
{
	for(int i = 1;i <= m; ++i)
	{
		printf("%lld\n", ans);
        printf("%d\n", i);
		int x = read(), pos = rk[x];
		ans -= ask_prefix(x, pos) + ask_suffix(x, pos);
		creat_tree(pos, x, -1);
	}
}
 
int main()
{
	init();
	solve();
	return 0;
}