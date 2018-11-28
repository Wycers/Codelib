#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

#include <cmath>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clri(x) memset(x,0x3f,sizeof(x))
#define Clre(x) memset(x,0x00,sizeof(x))
#define eps 1e-12
typedef long long ll;
using namespace std;
const int N = 20;
const double Inf = 1e5;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
struct point
{
	double x,y;
	point operator - (point b)
	{
		return (point){x - b.x,y - b.y};	
	};
	void Prt()
	{
		printf("%.2lf %.2lf\n",x,y);	
	}
} p[N];
double Dis(point a,point b)
{
	point t = a - b;
	return hypot(t.x,t.y);
}
struct Pic
{
	double K[30],B[30];int top;
	Pic()
	{
		top = 0;
	}
	void Insert(point a,point b)
	{
		point t = b - a;
		if (fabs(t.x) < eps)
		{
			K[++top] = Inf;
			B[top] = b.x;
			return;
		}
		K[++top] = t.y / t.x;
		B[top] = a.y - K[top] * a.x;
	}
	void Delete()
	{
		--top;	
	}
	pair<point,point> find(point a,point b)
	{
		pair<point,point> res = make_pair((point){Inf,Inf},(point){Inf,Inf});
		double x, y;
		if (fabs(a.x - b.x) < eps) //k == Inf
		{
			if (a.y > b.y) swap(a,b);
			for (int i=1;i<=top;++i)
				if (fabs(K[i] - Inf) > eps)
				{
					y = K[i] * a.x + B[i];
					if (y <= a.y && a.y - y < Dis(res.first,a))
						res.first = (point){a.x,y};
					if (y >= b.y && y - b.y < Dis(res.second,b))
						res.second = (point){b.x,y};
				}
			return res;
		}	
		if (fabs(a.y - b.y) < eps)
		{
			if (a.x > b.x) swap(a,b);
			for (int i=1;i<=top;++i)
				if (K[i] != 0)
				{
					if (fabs(K[i] - Inf) < eps)
						x = B[i];
					else 
						x = (a.y - B[i]) / K[i];
					if (x <= a.x && a.x - x < Dis(res.first,a))
						res.first = (point){x,a.y};
					if (x >= b.x && x - b.x < Dis(res.second,b))
						res.second = (point){x,b.y};
				}
			return res;	
		}
		if (a.x > b.x) swap(a,b);
		double k = (b.y - a.y) / (b.x - a.x);
		double bb = b.y - k * b.x;
		point temp;
		//puts("==================");
		for (int i=1;i<=top;++i)
			if (K[i] != k)
			{
				//puts("==-==");
				if (fabs(K[i] - Inf) < eps)
					temp.x = B[i];
				else 
					temp.x = (bb - B[i]) / (K[i] - k);
				temp.y = k * temp.x + bb; 
				//temp.Prt(); a.Prt();
				if (temp.x - a.x <= eps)
				{
					if (Dis(temp,a) < Dis(res.first,a))
						res.first = temp;	
				}
				if (b.x - temp.x <= eps)
				{
					if (Dis(temp,b) < Dis(res.second,b))
						res.second = temp;	
				}
				/*res.first.Prt();
				res.second.Prt();*/
			}	
		//puts("==================");
		return res;
	}
} P; 

//Code
int n,m,pn;
void Init()
{
	n = read(); m = read();
	pn = read();
	for (int i=1;i<=pn;++i)
	{
		p[i].x = (double)read();
		p[i].y = (double)read();	
	}
	P.Insert((point){0,0},(point){0,n});
	P.Insert((point){0,n},(point){m,n});
	P.Insert((point){m,n},(point){m,0});
	P.Insert((point){m,0},(point){0,0});
}
double Ans = 1e4;
bool used[N];
int s[N],top = 0;
void Dfs(int k,double res)
{
	if (k == pn)
	{
		
		/*if (res < Ans)
		{
			for (int i=1;i<=top;++i)
				printf("%d ",s[i]);
			printf("%.4lf\n",res);	
		}*/
		Ans = min(Ans,res);
		return;	
	}
	for (int i=1;i<=pn;++i)
	//for (int i=s[k];i<=s[k];++i)
	{
		if (used[i]) continue;
		pair<point,point> t = P.find(p[i],p[i % pn + 1]);
		P.Insert(t.first,t.second); used[i] = true; //s[++top] = i;
		/*t.first.Prt(); t.second.Prt();
		printf("====>%.4lf\n",Dis(t.first,t.second));*/
		Dfs(k + 1,res + Dis(t.first,t.second));
		P.Delete(); used[i] = false; //--top;
		//cout << "==>"; t.first.Prt(); t.second.Prt(); cout << endl;
	}
}
int main()
{
	Init();
	Clre(used);
	/*s[0] = 1;
	s[1] = 2;
	s[2] = 3;
	s[3] = 4;*/
	Dfs(0,0);
	printf("%.3lf\n",Ans); 
    return 0;
}
/*
2 2
3
0 0
0 2
2 0
*/
/*
10 10
4
1 2
2 3 
4 3
6 1
*/
