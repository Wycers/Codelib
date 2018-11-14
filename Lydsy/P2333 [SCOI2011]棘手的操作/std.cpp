#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#define inf 1000000000
using namespace std;
int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,Q,overadd;
int a[300005];
multiset<int> st;
void erase(int x)
{
	st.erase(st.find(x));
}
void insert(int x)
{
	st.insert(x);
}
struct Sheap{
	int ls[300005],rs[300005],fa[300005];
	int tag[300005],v[300005],q[300005];
	int tot;
	int find(int x){
		while(fa[x])x=fa[x];
		return x;
	}
	void pushdown(int k){
		if(!tag[k])return;
		int t=tag[k],l=ls[k],r=rs[k];
		tag[k]=0;
		if(l)tag[l]+=t,v[l]+=t;
		if(r)tag[r]+=t,v[r]+=t;
	}
	void solvetag(int x){
		while(x)q[++tot]=x,x=fa[x]; 
		while(tot)pushdown(q[tot--]);
	}
	int top(int x){
		return v[find(x)];
	}
	int merge(int x,int y){
		if(!x||!y)return x+y;
		if(v[x]<v[y])swap(x,y);
		pushdown(x);
		rs[x]=merge(rs[x],y);
		fa[rs[x]]=x;
		swap(ls[x],rs[x]);
		return x;
	}
    int del(int x){
		solvetag(x);
		int t=merge(ls[x],rs[x]),f=fa[x];
		ls[x]=rs[x]=fa[x]=0;
		if(x==ls[f])ls[f]=t;
		else rs[f]=t;
		fa[t]=f;
		return find(t);
	}
	void add(int x,int val){
	    solvetag(x);
		erase(v[find(x)]);
		v[x]+=val;
		insert(v[merge(x,del(x))]);
	}
	void heap_add(int x,int val){
		int p=find(x);
		tag[p]+=val;v[p]+=val;
		erase(v[p]-val);insert(v[p]);
	}
	void addedge(int x,int y){
		int t1=find(x),t2=find(y);
		if(t1!=t2)
		{
			if(merge(t1,t2)==t1)st.erase(st.find(v[t2]));
			else st.erase(st.find(v[t1]));
		}
	}
}q;
int main()
{
	freopen("a.in","r",stdin);
	freopen("std.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)q.v[i]=a[i];
	for(int i=1;i<=n;i++)st.insert(a[i]);
	Q=read();
	char ch[3];int x,v;
	while(Q--)
	{
		scanf("%s",ch+1);
		if(ch[1]=='A'){
			if(ch[2]=='1')
				x=read(),v=read(),q.add(x,v);
			if(ch[2]=='2')
				x=read(),v=read(),q.heap_add(x,v);
			if(ch[2]=='3')
				x=read(),overadd+=x;
		}		
		else if(ch[1]=='F'){
			if(ch[2]=='1')
			{
				x=read();q.solvetag(x);
				printf("%d\n",q.v[x]+overadd);
			}
			if(ch[2]=='2')
				x=read(),printf("%d\n",q.top(x)+overadd);
			if(ch[2]=='3')
				printf("%d\n",*--st.find(inf)+overadd);
		}
		else x=read(),v=read(),q.addedge(x,v);
	}
	return 0;
}
