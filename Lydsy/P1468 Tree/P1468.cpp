#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 40005
struct edge_
{
	int to,next,v;
} edge[N*2];
int n,k,head[N],cnt;
void Insert(int u,int v,int w)
{
	edge[++cnt].to=v;
	edge[cnt].v=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
void Readin()
{
	scanf("%d",&n);
	int u,v,w;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		Insert(u,v,w);
		Insert(v,u,w);
	}
	scanf("%d",&k);
}
class mystery
{
	private:
		bool vis[N];
		int stage[N],deep[N],f[N],son[N];
		int root,ans,sum;
		
		void GetRoot(int x,int fa)
		{
			son[x]=1;f[x]=0;
			for (int i=head[x];i;i=edge[i].next)
			{
				int v=edge[i].to;
				if (v==fa||vis[v]) continue;
				GetRoot(v,x);
				son[x]+=son[v];
				f[x]=max(f[x],son[v]);
			}
			f[x]=max(f[x],sum-son[x]);
			if (f[x]<f[root]) root=x;
		}
		
		void GetDeep(int x,int fa)
		{
			stage[++stage[0]]=deep[x];
			for (int i=head[x];i;i=edge[i].next)
			{
				int v=edge[i].to;
				if (v==fa||vis[v]) continue;
				deep[v]=deep[x]+edge[i].v;
				GetDeep(v,x);
			}
		}
		
		int Cal(int x,int now)
		{
			deep[x]=now;
			stage[0]=0;
			GetDeep(x,0);
			sort(stage+1,stage+stage[0]+1);
			int t=0;
			for (int l=1,r=stage[0];l<r;)
			{
				if (stage[l]+stage[r]<=k)
				{
					t+=r-l;
					l++;
				} else r--;
			}
			return t;
		}
		
		void Work(int x)
		{
			ans+=Cal(x,0);
			vis[x]=true;
			for(int i=head[x];i;i=edge[i].next)
			{
				int v=edge[i].to;
				if(vis[v]) continue;
				ans-=Cal(v,edge[i].v);
				sum=son[v];
				root=0;
				GetRoot(v,root);
				Work(root);
			}
		}
		
	public:
		void Solve()
		{
			memset(vis,false,sizeof(vis)); 
			sum=n;
			f[0]=0x7fffffff;
			GetRoot(1,0);
			Work(root);
			printf("%d\n",ans);
		}
} Stupid;
int main()
{
	Readin();
	Stupid.Solve();
	return 0;
}
