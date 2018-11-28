#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 4e5 + 10;
const double Alpha = 0.7;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
int n, m;
map<int, int> mp;
//Struct
struct node
{
	node *ch[2];
	int l, r, lsize, tsize, size, key;
	bool exist;
	bool Balance()
	{
		return (ch[0]->lsize <= lsize * Alpha && ch[1]->lsize <= lsize * Alpha);
	}
	void Update()
	{
		size = exist * (r - l + 1) + ch[0]->size + ch[1]->size;
		tsize = exist + ch[0]->tsize + ch[1]->tsize;
		lsize = 1 + ch[0]->lsize + ch[1]->lsize;
	}
};
struct ScapeGoatTree
{
	node a[N];
	node *bc[N]; int cnt;
	node *null, *root, * tail;
	void Init()
	{
		tail = a;
		null = tail++;
		null->ch[0] = null->ch[1] = null;
		null->l = null->r = 0; 
		null->size = null->tsize = null->lsize = null->key = 0;
		root = null;
		cnt = 0;
	}
	node *newNode(int l, int r, int key)
	{
		node *p;
		if (cnt)
			p = bc[cnt--];
		else
			p = tail++;
		p->l = l, p->r = r, p->key = key;
		p->ch[0] = p->ch[1] = null;
		p->size = r - l + 1;
		p->lsize = p->tsize = p->exist = 1;
		return p;
	}
	void Travel(node *p, vector<node *> &v)
	{
		if (p == null)
			return;
		Travel(p->ch[0], v);
		if (p->exist)
			v.push_back(p);
		else
			bc[++cnt] = p;
		Travel(p->ch[1], v);
	}
	node *split(vector<node *> &v, int l, int r)
	{
		if (l >= r)
			return null;
		int mid = (l + r) >> 1;
		node *p = v[mid];
		p->ch[0] = split(v, l, mid);
		p->ch[1] = split(v, mid + 1, r);
		p->Update();
		return p;
	}
	void Rebuild(node *&p)
	{
		vector<node *> v;
		Travel(p, v);
		p = split(v, 0, v.size());
	}
	node **Insert(node *&p, int l, int r, int key)
	{
		if (p == null)
		{
			p = newNode(l, r, key);
			return &null;
		}
		node **res = Insert(p->ch[r >= p->l], l, r, key);
		p->tsize++; p->lsize++;
		p->Update();
		if (!p->Balance())
			res = &p;
		return res;
	}
	void Insert(int l, int r, int key)
	{
		node **p = Insert(root, l, r, key);
		if(*p != null)
			Rebuild(*p);
	}
	void Del(node *p, int id)
	{
		if (p == null)
			return;
		if (p->exist && p->l <= id && id <= p->r)
		{
			if (p->l == p->r)
			{
				p->tsize--;
				p->exist = false;
			}
			else if (p->l == id)
			{
				p->l++;
				p->key++;
			}
			else if (p->r == id)
				p->r--;
			else
			{
				int now = p->r;
				p->r = id - 1;
				Insert(id + 1, now, id + 1);
			}
			p->Update();
			return;
		}
		if (id < p->l)
			Del(p->ch[0], id);
		else
			Del(p->ch[1], id);
		p->Update();
	}
    void Del(int val)
	{
		Del(root, val);
		if (root->tsize < Alpha * root->lsize)
			Rebuild(root);
	}
    int Getrank(node *k, int pos)
    {
        if (k == null) return 0;
        if (k->exist && k->l <= pos && k->r >= pos) 
            return (pos - k->l + 1) + k->ch[0]->size;
        if (k->l > pos)  
            return Getrank(k->ch[0], pos);
        return Getrank(k->ch[1], pos) + k->ch[0]->size + k->exist * (k->r - k->l + 1);
    }
    int Getindex(node *k, int x)
    {
        if (k == null) return 0;
        if (x <= k->ch[0]->size) 
            return Getindex(k->ch[0], x);
        else if (k->exist && k->ch[0]->size < x && k->ch[0]->size + k->exist * (k->r - k->l + 1) >= x)
        {
            if (k->l == k->r)
				return k->key;  
            else
				return x - k->ch[0]->size - 1 + k->l;   
        }
        else return Getindex(k->ch[1], x - k->ch[0]->size - k->exist * (k->r - k->l + 1) );
    }
    int Getrank(int pos)
    {
    	return Getrank(root, pos);
	}
    int GetKth(int pos)
    {
    	return Getindex(root, pos);
	}
} Tree;
//Code
int main()
{
	n = read(); m = read();
	Tree.Init();
    Tree.Insert(1, n, 1);
    int mn = 0, mx = n, a = 0, opt, x, y, pos;
    while (m--)
    {
        opt = read(); x = read() - a;
        if (opt <= 3)
        {
        	if ((pos = mp[x]) == 0)
        		pos = x;
        	if (opt == 1)
	        {
	            y = read() - a;
	            printf("%d\n", a = Tree.Getrank(pos));
	            Tree.Del(pos);
	            Tree.Insert(pos, pos, y);
	            mp[x] = 0;
	            mp[y] = pos;
	        }   
	        else if (opt == 2)
	        {
	            printf("%d\n", a = Tree.Getrank(pos));
	            Tree.Del(pos);
	            mp[x] = pos = --mn;
	            Tree.Insert(pos, pos, x);
	        }
	        else 
	        {
	            printf("%d\n", a = Tree.Getrank(pos));
	            Tree.Del(pos);
	            mp[x] = pos = ++mx;
	            Tree.Insert(pos, pos, x);    
	        }
		}
        else
            printf("%d\n", a = Tree.GetKth(x));
	}
    return 0;
}


