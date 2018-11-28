#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,fnum,m,now,ed;
char heck[2001];
struct player
{
	bool f,jump,like;
	int hp,num;
	bool zhuge,used[2001];
	char hd[2001];
}a[11];
bool mp(int k){if(k==0)return 1;return 0;}
bool zp(int k){if(a[k].f==0&&k!=0)return 1;return 0;}
bool fp(int k){if(a[k].f==1)return 1;return 0;}
void discard(int k){a[k].num=a[k].zhuge=0;}
void ini()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		char ch[5];scanf("%s",ch);
		if(ch[0]=='F'){a[i].f=1;fnum++;}
		for(int j=1;j<=4;j++)
	       scanf(" %c",&a[i].hd[j]);
        a[i].num=a[i].hp=4;
	}
	for(int i=0;i<m;i++)
	   scanf(" %c",&heck[i]);
    if(!fnum)ed=1;
}
int dis(int x,int y)
{
	int d=1;
	for(int i=(x+1)%n;i!=y;i=(i+1)%n)
        if(a[i].hp)d++;
    return d;
}
void reset(int k)
{
	int tot=0;
	for(int i=1;i<=a[k].num;i++)
		if(!a[k].used[i])
		{
		   tot++;
		   a[k].hd[tot]=a[k].hd[i];
		   a[k].used[tot]=0;
	    }
	a[k].num=tot;
}
void showhand(int k)
{
	reset(k);
    for(int i=1;i<=a[k].num;i++)
    {
        printf("%c",a[k].hd[i]);
        if(i!=a[k].num)printf(" ");
    }
    printf("\n");
}
void gethand(int k,int num)
{
	if(ed)return;
	for(int i=1;i<=num;i++)
	{
		a[k].num++;
	    a[k].hd[a[k].num]=heck[now];
	    a[k].used[a[k].num]=0;
	    if(now<m-1)now++;
	}
}
void kill(int k,int from)
{
	if(mp(k)){ed=2;return;}
    if(fp(k))
    {
   	   fnum--;
   	   if(!fnum)ed=1;
	   gethand(from,3);
    }
    if(zp(k)&&mp(from))discard(from);
    }
void jump(int k){a[k].jump=1;}
bool usecard(int k,char c)
{
    for(int i=1;i<=a[k].num;i++)
       if(a[k].hd[i]==c&&!a[k].used[i])
          {a[k].used[i]=1;return 1;}
    return 0;
}	
bool sha(int k){return usecard(k,'K');}
bool shan(int k){return usecard(k,'D');}
bool tao(int k){return usecard(k,'P');}
bool wuxie(int k){if(usecard(k,'J')){jump(k);return 1;}return 0;}
void like(int k){if(!a[k].jump)a[k].like=1;}
void wound(int k,int from)
{
   a[k].hp--;
   if(a[k].hp==0)
   {
   	  if(tao(k))a[k].hp=1;
      else kill(k,from);
   }
}
bool askwuxie(int k,int f)
{ 
    int i=k;
    while(1)
    {
    	if(a[i].hp)
	        if(a[i].f==f)
    	    	if(wuxie(i))
                {  
			        if(!askwuxie(i,f^1))return 1;
                    return 0;
                }
        i=(i+1)%n;
        if(i==k)return 0;
    }
}
bool needwuxie(int k,int from)
{
	if(!a[k].jump&&!mp(k))return 0;
    if(askwuxie(from,a[k].f))return 1;
    return 0;
}
void aoe(int k,int f)
{
	for(int i=(k+1)%n;i!=k;i=(i+1)%n)if(a[i].hp)
	{
	   if(needwuxie(i,k))continue;
	   if(f==1){if(!sha(i)){if(mp(i))like(k);wound(i,k);}}
	   if(f==2){if(!shan(i)){if(mp(i))like(k);wound(i,k);}}
	   if(ed)return;
    }
}
int duel(int k,int from)
{
	if(zp(k)&&mp(from))return 1;
	if(needwuxie(k,from))return 2;
	while(1)
	{
		if(!sha(k))return 1;
		if(!sha(from))return 0;
	}
}
bool attack(int k,int f)
{
	if(fp(k))
	{
		if(dis(k,0)==1&&f==1){jump(k);if(!shan(0))wound(0,k);return 1;}
		if(f==2)
		{
		    jump(k);
		    int res=duel(0,k);
			if(res==1)wound(0,k);
			else if(res==0)wound(k,0);
			return 1;
		}
	}
	if(mp(k))
	{
       for(int i=(k+1)%n;i!=k;i=(i+1)%n)if(a[i].hp)
	      if((fp(i)&&a[i].jump)||(a[i].like&&!a[i].jump))
	      {
	         if(dis(k,i)==1&&f==1)
	         {
                 if(!shan(i))wound(i,k);
                 return 1;
             }
             if(f==2)
		     {
		         int res=duel(i,k);
			     if(res==1)wound(i,k);
			     else if(res==0)wound(k,i);
		         return 1;
		     }
		 }
	}
	else for(int i=(k+1)%n;i!=k;i=(i+1)%n)if(a[i].hp)
	   if((a[k].f^a[i].f)&&a[i].jump)
	   {
	      if(dis(k,i)==1&&f==1)
	      {
              jump(k);
              if(!shan(i))
              wound(i,k); 
              return 1;
          }
          if(f==2)
		  {
	          jump(k);
		      int res=duel(i,k);
			  if(res==1)wound(i,k);
              else if(res==0)wound(k,i);
		      return 1;
		  }
	   }
    return 0;
}
void move(int k)
{   
    reset(k);
	gethand(k,2);
	bool flag=0;
	for(int i=1;i<=a[k].num;i++)
	{
		if(ed||!a[k].hp)return;
		if(a[k].used[i]==1)continue;
		if(a[k].hd[i]=='P'&&a[k].hp<4)
  		    {a[k].used[i]=1;a[k].hp++;}
        else if(a[k].hd[i]=='N'){a[k].used[i]=1;aoe(k,1);i=0;}
        else if(a[k].hd[i]=='W'){a[k].used[i]=1;aoe(k,2);i=0;}
        else if(a[k].hd[i]=='K'&&(!flag||a[k].zhuge))
        {
        	if(attack(k,1))
			{   
			   a[k].used[i]=1;
			   flag=1;
			   i=0;
            }
        }
        else if(a[k].hd[i]=='F')
        {
        	if(attack(k,2)){a[k].used[i]=1;i=0;}
        }
        else if(a[k].hd[i]=='Z')
		{a[k].used[i]=1;if(!a[k].zhuge){a[k].zhuge=1;i=0;}}
	}
}
void solve()
{
	for(int i=0;i<n;i++)
       if(a[i].hp)move(i);
}
void print()
{
	if(ed==1)printf("MP\n");
	else if(ed==2)printf("FP\n");
	for(int i=0;i<n;i++)
	   if(!a[i].hp)printf("DEAD\n");
       else showhand(i);
}
int main()
{
	ini();
	while(!ed)solve();
	print();
	return 0;
}
