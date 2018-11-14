#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct

//Code
char str[300];
int st[300], top = 0; bool avi[300];
void Modify(int s, int t)
{
	bool flag1 = false, flag2 = false; 
	int tot = 0;
	for (int i = s + 1; i <= t - 1; ++i)
	{
		if (avi[i] && str[i] == '(')
			++tot;
		if (avi[i] && str[i] == ')')
			--tot;
		if (tot)
			continue;
		if (str[i] == '+' || str[i] == '-')
			flag1 = true;
		if (str[i] == '*' || str[i] == '/')
			flag2 = true;
	}
	int type = flag2 << 1 | flag1;
	if ((str[s - 1] == '(') && (str[t + 1] == ')'))
		goto Die;
	if ((type & 1) == 0)
		goto Die;
	else if ((str[s - 1] == '+' || str[s - 1] == '-' || str[s - 1] == '(') && (str[t + 1] == '+' || str[t + 1] == '-' || str[t + 1] == ')'))
			goto Die;
	return;
	
	Die:
	avi[s] = false; avi[t] = false;
	if (str[s - 1] == '-')
	{
		for (int i = s + 1; i <= t - 1; ++i)
		{
			if (avi[i] && str[i] == '(')
				++tot;
			if (avi[i] && str[i] == ')')
				--tot;
			if (tot)
				continue;
			if (str[i] == '+')
				str[i] = '-';
			else if (str[i] == '-')
				str[i] = '+';
		}
	}
	else if (str[s - 1] == '/')
	{
		for (int i = s + 1; i <= t - 1; ++i)
		{
			if (avi[i] && str[i] == '(')
				++tot;
			if (avi[i] && str[i] == ')')
				--tot;
			if (tot)
				continue;
			if (str[i] == '*')
				str[i] = '/';
			else if (str[i] == '/')
				str[i] = '*'; 
		}
	}
}
void Work()
{
	int len = strlen(str + 1);
	str[0] = '('; str[len + 1] = ')';
	for (int i = 1; i <= len; ++i)
	{
		if (str[i] == '(')
			st[++top] = i;
		else if (str[i] == ')')
			Modify(st[top--], i);
	}
	for (int i = 1; i <= len; ++i)
		if (avi[i])
			printf("%c", str[i]);
	puts("");
}
int main()
{
	int n = read();
    for (int i = 1; i <= n; ++i)
    {
    	Clr(str, 0); Clr(avi, true); 
    	scanf("%s", str + 1);
		Work();
	}
	return 0;
}
