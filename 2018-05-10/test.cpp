#include<cstdio>
#include<queue>
using namespace std;
const double EPS=0.00000001;
double ave;
struct data{
	double x,y,val;
	data(const double &x,const double &y){
		this->x=x;
		this->y=y;
		val=x*x/y-x*x/(y+1.0);
	}
	data(){}
};
bool operator < (const data &a,const data &b){
	return a.val<b.val;
}
priority_queue<data>Heap;
int a[200005];
double sqr(const double &x){
	return x*x;
}
int T,n,m;
int main(){
	//freopen("b.in","r",stdin);
	scanf("%d",&T);
	for(int zu=1;zu<=T;++zu){
		while(!Heap.empty()){
			Heap.pop();
		}
		scanf("%d%d",&n,&m);
		ave=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			ave+=(double)a[i];
		}
		ave/=(double)m;
		double tt=0;
		for(int i=1;i<=n;++i){
			tt+=sqr((double)a[i]-ave);
		}
		double ans=tt+sqr(ave)*(double)(m-n);
		for(int i=1;i<=n;++i){
			Heap.push(data((double)a[i],1.0));
		}
		for(int i=1;i<=m-n;++i){
			data t=Heap.top(); Heap.pop();
			if(t.val<EPS){
				break;
			}
			Heap.push(data(t.x,t.y+1.0));
			ans-=t.val;
		}
		printf("Case #%d: %.12f\n",zu,ans/(double)m);
	}
	return 0;
}