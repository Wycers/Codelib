#include <stdio.h>
#include <algorithm>
#include <queue>
#define MAXN 170000
using namespace std;
struct T
{
	int t1,t2;
	friend bool operator<(T a,T b){return a.t2<b.t2;} //排序用
}a[MAXN];
priority_queue<int>q; //大根堆q保存已经修理的建筑的各自的修理所需时间
int main()
{
	int i,j,n,nowtime=0; //nowtime=当前时间
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i].t1,&a[i].t2);
	sort(a+1,a+n+1); //按结束时间升序排序
	for(i=1;i<=n;i++)
	{
		if(nowtime+a[i].t1<=a[i].t2) //如果修完第i个建筑后的时间比第i个建筑消失时间早
		{	
			nowtime+=a[i].t1; //当前时间加上第i个建筑所需修理时间
			q.push(a[i].t1); //将第i个建筑所需修理时间入队
		}
		//否则，在第i个建筑消失前不能修好它，那么就需要判断是否需要舍掉之前一个修过的建筑，腾出时间修这个建筑
		else if(nowtime+a[i].t1-q.top()<=a[i].t2&&a[i].t1<=q.top()) //不修之前最费时的建筑后，这个建筑能修好，且建筑i费时比那个建筑少，那个就舍掉那个最费时的建筑
		{
			nowtime=nowtime+a[i].t1-q.top();
			q.pop();
			q.push(a[i].t1);
		}
	}
	printf("%d\n",q.size()); //最终大根堆里的元素数目就是抢救回来的最多建筑数
	return 0;
}
