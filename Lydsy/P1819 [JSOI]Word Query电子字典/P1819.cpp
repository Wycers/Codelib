#include <iostream>
#include <cstdio>
#include <cstring>
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
struct node
{
	node *ch[26]; 
	int tim, tag; bool end;
};
struct Tire
{
	node *root, *null, *end;
	node* newNode()
	{
		node *p = new node;
		for (int i = 0; i < 26; ++i)
			p->ch[i] = null;
		p->tim = 0;
		p->end = false;
		p->tag = 0;
		return p;
	}
	void Init()
	{
		null = newNode();
		root = newNode();
		end = newNode();
	}
	void Insert(char str[])
	{
		node *now = root; int len = strlen(str);
		for (int i = 0; i < len; ++i)
		{
			if (now->ch[str[i] - 'a'] == null)
				now->ch[str[i] - 'a'] = newNode();
			now = now->ch[str[i] - 'a'];
		}
		now->end = true;
		++now->tim;
	}
	int Match(char str[], int t)
	{
		node *now = root; int len = strlen(str);
		for (int i = 0; i < len; ++i)
		{
			if (now->ch[str[i] - 'a'] == null)
			{
				return 0;
			}
			now = now->ch[str[i] - 'a'];
		}
		if (now->end && t != now->tag)
		{
			now->tag = t;
			return now->tim;
		}
		return 0;
	}
} Tree;
//Code
int n, m; char str[25]; 
void Work(int t)
{
	char nstr[25]; int len = strlen(str), res = 0, cnt = 0;
	for (int j = 0; j <= len; ++j)
		nstr[j + 1] = str[j];
	for (int i = 0; i < 26; ++i)
	{
		nstr[0] = i + 'a';
		res += Tree.Match(nstr, t);
	}
	for (int j = 0; j < len; ++j)
		nstr[j] = str[j];
	for (int i = 0; i < 26; ++i)
	{
		nstr[len] = i + 'a';
		nstr[len + 1] = '\0';
		res += Tree.Match(nstr, t);
	}
	for (int j = 0; j <= len; ++j)
		nstr[j] = str[j];
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			nstr[i] = j + 'a';
			res += Tree.Match(nstr, t); 
		}
		nstr[i] = str[i];
	}
	nstr[0] = str[0];
	for (int i = 2; i <= len; ++i)
		nstr[i] = str[i - 1]; 
	for (int i = 1; i < len; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			nstr[i] = 'a' + j;
			res += Tree.Match(nstr, t);
		}
		swap(nstr[i], nstr[i + 1]);
	}
	for (int i = 0; i < len; ++i)
	{
		for (int j = i + 1; j <= len; ++j)
			nstr[j - 1] = str[j];
		res += Tree.Match(nstr, t);
		nstr[i] = str[i]; 
	}
	printf("%d\n", res);
}
int main()
{
	n = read(); m = read(); 
	Tree.Init();
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", str);
		Tree.Insert(str);
	}
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s", str);
		if (Tree.Match(str, i))
		{
			puts("-1");
			continue;
		}
		Work(i);
	}
    return 0;
}


