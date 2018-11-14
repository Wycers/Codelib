#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
string s1[4]={"U","A1","A2","A3"};
string s2[3]={"F1","F2","F3"};
int main()
{
	freopen("a.in","w",stdout);
	srand(time(0));
	int n=100000,m=10000;
	cout<<n<<endl;
	for(int i=1;i<=n;i++)cout<<0<<' ';cout<<endl;
	cout<<5*m<<endl;
	for(int i=1;i<=m;i++)
	{
		int u=rand()%n+1,v=rand()%n+1;
		string s=s1[rand()%4];
		cout<<s<<' ';
		if(s=="U")cout<<u<<' '<<v;
		else if(s!="A3")cout<<u<<' '<<-v;
		else cout<<u;
		cout<<endl;
	}
	for(int i=1;i<=4*m;i++)
	{
		int u=rand()%n+1,v=rand()%n+1;
		string s=s2[rand()%3];
		cout<<s<<' ';
		if(s!="F3")cout<<u;
		cout<<endl;
	}
	return 0;
}
