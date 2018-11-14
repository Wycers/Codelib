#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define M 20100
using namespace std;
struct abcd{
	int x,y;
}points[M];
int n,v[M];
int stack[M],top;
bool DFS(int L,int dpt)
{
	int i,j,bottom=top;
	int minx=0x3f3f3f3f,maxx=0xefefefef;
	int miny=0x3f3f3f3f,maxy=0xefefefef;
	if(top==n)
		return true;
	if(dpt==3)
		return false;
	for(i=1;i<=n;i++)
		if(!v[i])
		{
			minx=min(minx,points[i].x);
			maxx=max(maxx,points[i].x);
			miny=min(miny,points[i].y);
			maxy=max(maxy,points[i].y);
		}
	int dx[]={minx,minx,maxx-L,maxx-L};
	int dy[]={miny,maxy-L,miny,maxy-L};
	for(j=0;j<4;j++)
	{
		for(i=1;i<=n;i++)
			if(!v[i])
				if(points[i].x>=dx[j]&&points[i].x<=dx[j]+L)
					if(points[i].y>=dy[j]&&points[i].y<=dy[j]+L)
						v[i]=1,stack[++top]=i;
		bool flag=DFS(L,dpt+1);
		while(top!=bottom)
			v[stack[top--]]=0;
		if(flag)
			return true;
	}
	return false;
}
int Bisection()
{
	int l=0,r=0x3f3f3f3f;
	while(l+1<r)
	{
		int mid=l+r>>1;
		if( DFS(mid,0) )
			r=mid;
		else
			l=mid;
	}
	if( DFS(l,0) )
		return l;
	return r;
}
int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		scanf("%d%d",&points[i].x,&points[i].y);
	cout<<Bisection()<<endl;
}
