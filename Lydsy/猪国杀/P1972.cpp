#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
char card[2100]; int now = 0, m, n;
bool end = false;
int next[2100], last[2100];
int F(int x, int y);
bool J(int k, int x, int y);
bool act(int k);
bool Judge();
void Debug();
struct Pig
{
	int id, status, hp, pre, nxt, top;
	bool equ, kill;
	char cd[2010]; bool used[2010];
	void Init()
	{
		char str[10];
		scanf("%s", str);
		status = 0;
		switch (str[0])
		{
			case 'M':
				id = 1;
				status = 3; 
				break;
			case 'Z':
			 	id = 2;
			 	break;
			case 'F':
				id = 3;
				break;
		}
		for (int i = 1; i <= 4; ++i)
		{
			scanf("%s", str);
			cd[i] = str[0]; 
			used[i] = false;
		}
		hp = top = 4;
		equ = false;
	}
	void Getcard(int k)
	{
		for (int i = 1; i <= k; ++i)
		{
			if ((++now) > m)
				now = m;
			cd[++top] = card[now]; 
			used[top] = false;
		}
	}
	void Usecard(int k)
	{
		//printf("Someone uses %c\n", cd[k]);
		used[k] = true;
	}
	void Prt()
	{
		int cnt = 0;
		for (int i = 1; i <= top; ++i)
			if (used[i] == false)
				++cnt;
		for (int i = 1; i <= top; ++i)
			if (used[i] == false)
			{
				printf("%c", cd[i]);
				if (--cnt)
					printf(" ");
			}
		puts("");
	}
	bool Findcard(char need)
	{
		for (int i = 1; i <= top; ++i)
			if (used[i] == false && cd[i] == need)
			{
				Usecard(i);
				used[i] = true;
				return true;
			}
		return false;
	} 
	bool killed(char need)
	{
		if (Findcard(need))
			return false;
		--hp;
		return true;
	}
	bool Godie()
	{
		if (hp > 0)
			return false;
		if (Findcard('P'))
		{
			hp = 1;
			return false; 
		} 
		return true;
	}
	void Act(int k)
	{
		Getcard(2);
		//Prt();
		kill = false;
		//Debug();
		while (act(k))
		{
		//	Debug();
		//	system("pause");
		}
		//puts("end");*/
	}
} p[10];
void Debug()
{
	for (int i = 1; i <= n; ++i) 
	{
		printf("%d : Hp:%d Equ:%d Sta:%d ", i, p[i].hp, p[i].equ, p[i].status);
		p[i].Prt(); 
	}
}
int F(int x, int y) //x响应y的决斗，返回谁掉血了。 
{
	if (p[x].id == 2 && p[y].id == 1)
		return x;
	if (p[x].Findcard('K'))
		return F(y, x);
	return x;
}
bool J(int k, int x, int y) //从k开始询问对x有y(0无益/1有益)的锦囊是否能够生效 
{
	bool flag = true;
	for (int i = k; i != k || flag; i = p[i].nxt)
	{
		flag = false;
		if (p[i].id == 1)
		{
			if (p[x].status >= 3 && y == 0 && p[i].Findcard('J'))
				return J(i, x, 1) ^ 1;
			if (p[x].status == 2 && y == 1 && p[i].Findcard('J'))
				return J(i, x, 0) ^ 1;
		}
		if (p[i].id == 2)
		{
			if (p[x].status >= 3 && y == 0 && p[i].Findcard('J'))
			{
				p[i].status = 4;
				return J(i, x, 1) ^ 1; 
			}
			if (p[x].status == 2 && y == 1 && p[i].Findcard('J'))
			{
				p[i].status = 4;
				return J(i, x, 0) ^ 1;
			}
		}
		if (p[i].id == 3)
		{
			if (p[x].status == 2 && y == 0 && p[i].Findcard('J'))
			{
				p[i].status = 2;
				return J(i, x, 1) ^ 1;
			}
			if (p[x].status >= 3 && y == 1 && p[i].Findcard('J'))
			{
				p[i].status = 2;
				return J(i, x, 0) ^ 1;
			}
		}
	}
	return true;
} 
int Gettar(int k)
{
	for (int i = p[k].nxt; i != k; i = p[i].nxt)
	{	
		if (p[i].hp <= 0)
	        continue;
		if (p[k].id == 1)
		{
			if (!p[i].status)
				continue;
			if (p[i].status <= 2)
				return i;
		}
		if (p[k].id == 2 && p[i].status == 2)
			return i;
		if (p[k].id == 3 && p[i].status >= 3)		                        
			return i;
	}
	return -1;
}
bool Judge()
{
	if (p[1].hp <= 0)
	{
		puts("FP");
		return end = true;
	}
	bool flag = true;
	for (int i = 1; i <= n; ++i)
		if (p[i].id == 3 && p[i].hp)
			flag = false;
	if (flag)
	{
		puts("MP");
		return end = true;
	}
	return false;
}
bool Godie(int x, int y)
{
	if (p[y].Godie())
	{
		for (int i = 1; i <= n; ++i)
			if (p[i].hp <= 0)
			{
				p[p[i].pre].nxt = p[i].nxt;
				p[p[i].nxt].pre = p[i].pre;
			}
		if (Judge())
			return true;
		if (p[x].id == 1 && p[y].id == 2)
		{
			p[x].top = 0;
			p[x].equ = false;
			return false;
		}
		if (p[y].id == 3)
			p[x].Getcard(3);
	}
	return false;
}
bool act(int k)
{
	int tar, loser;
	for (int i = 1; i <= p[k].top; ++i)
	{
		if (p[k].used[i])
			continue;
		switch (p[k].cd[i])
		{
			case 'P':
				if (p[k].hp < 4)
				{
					p[k].Usecard(i);
					++p[k].hp;
					return true;
				}
				break;
			case 'N':
				p[k].Usecard(i);
				for (int pig = p[k].nxt; pig != k; pig = p[pig].nxt)
				{
					if (J(k, pig, 0) && p[pig].killed('K'))
					{
						if (p[pig].id == 1 && !p[k].status)
							p[k].status = 1;
						Godie(k, pig);
						if (end)
							return false;
					}
				}
				return true;
			case 'W':
				p[k].Usecard(i);
				for (int pig = p[k].nxt; pig != k; pig = p[pig].nxt)
				{
					if (J(k, pig, 0) && p[pig].killed('D'))
					{
						if (p[pig].id == 1 && !p[k].status)
							p[k].status = 1;
						Godie(k, pig);
						if (end)
							return false;
					}
				}
				return true;
			case 'K':
				tar = Gettar(k);
				//printf("%d %d \n", k, tar);
				if (tar != p[k].nxt || (p[k].kill && !p[k].equ))
					break;
				p[k].Usecard(i);
				if (p[tar].status >= 3)
					p[k].status = 2;
				else if (p[tar].status == 2)
					p[k].status = 4;
				p[tar].killed('D');
				Godie(k, tar);
				if (end)
					return false;
				p[k].kill = true;
				return true;
			case 'F':
				tar = Gettar(k);
				if (p[k].id == 3)
					tar = 1;
				if (tar == -1)
					break;
				p[k].Usecard(i);
				if (p[tar].status >= 3)
					p[k].status = 2;
				else if (p[tar].status == 2)
					p[k].status = 4;
				if (!J(k, tar, 0))
					return true;
				loser = F(tar, k);
				p[loser].hp--;
				Godie(k, loser);
				if (end)
					return false;
				return true;
			case 'Z':
				p[k].Usecard(i);
				p[k].equ = true;
				return true;
		}
	}
	return false;
}
void Prt()
{
	for (int i = 1; i <= n; ++i)
	{
		if (p[i].hp)
			p[i].Prt();
		else
			puts("DEAD");
	}
}


//Code
int main()
{
	n = read(); m = read();
	for (int i = 1; i <= n; ++i)
	{
		p[i].Init();
		p[i].pre = i - 1;
		p[i].nxt = i + 1;
	}
	p[1].pre = n; p[n].nxt = 1;
	char str[5];
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s", str);
		card[i] = str[0];
	}
	if (Judge())
	{
		Prt();
		return 0;
	}
	for (int i = 1; ; i = p[i].nxt)
	{
		if (p[i].hp)
			p[i].Act(i);
		if (end || Judge())
		{
			Prt();
			return 0;
		} 
		//system("pause");
	}
    return 0;
}

