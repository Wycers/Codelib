#include <cstdio>
#include <set>
#include <cstring>
#define N 300010
using namespace std;
multiset<int> st;

void Erase(int val)
{
	st.erase(st.find(val));
}
void Insert(int val)
{
	st.insert(val);
}
int Read()
{
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || '9' < ch)
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9')
	{
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}

struct Heap
{
	Heap *l,*r,*fa;
	int v,tag;
	Heap()
	{
		l = r = fa = NULL;
		v = tag = 0;
	}
	void DownTag()
	{
		if (tag)
		{
			if (l != NULL)
                l->tag += tag,l->v += tag;
			if (r != NULL)
                r->tag += tag,r->v += tag;
			tag = 0;
		}
	}
} h[N];
Heap *stack[N];
int All_tag = 0,n;

Heap* Find(Heap *k)
{
	while (k->fa != NULL)
		k = k->fa;
	return k;
}

void Tag(Heap *k)
{
	int cnt = 0;
	while (k != NULL)
		stack[++cnt] = k,k = k->fa;
	while (cnt)
		stack[cnt--]->DownTag();
}

Heap *Merge(Heap *x,Heap *y)
{
    if (x == NULL)
        return y;
    if (y == NULL)
        return x;
    if(x->v < y->v)
        swap(x,y);
    x->DownTag();
    x->r = Merge(x->r,y);
    x->r->fa = x;
    swap(x->l,x->r);
    return x;
}

void Unite(int x,int y)
{
    Heap *p = Find(&h[x]);
    Heap *q = Find(&h[y]);
    if (p != q)
    {
        if(Merge(p,q) == p)
            st.erase(st.find(q->v));
        else
            st.erase(st.find(p->v));
    }
}

Heap *Del(Heap *x)
{
    Tag(x);
    Heap *t = Merge(x->l,x->r);
    Heap *f = x->fa;
    x->l = x->r = x->fa = NULL;
    if (f == NULL)
    {
		x = t;
		return t;
	}
	if (t == NULL)
	{
		f->l = f->r = NULL;
		return f;
	}
	if(x == f->l)
		f->l = t;
	else
		f->r = t;
	t->fa = f;
    return Find(t);
}

void P_point(Heap *x,int val)
{
    Tag(x);
    Erase(Find(x)->v);
    x->v += val;
    Insert(Merge(x,Del(x))->v);
}

void P_block(Heap *x,int val)
{
    Heap *p = Find(x);
    Erase(p->v);
    p->tag += val;
    p->v += val;
    Insert(p->v);
}

int Top(int x)
{
    return Find(&h[x])->v;
}

void Readin()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		h[i].v = Read();
		st.insert(h[i].v);
	}
}

void Solve()
{
	int Q = Read(),x,y;char opt[3];
	while (Q--)
	{
		scanf("%s",opt);
		printf("%s\n",opt);
		if (opt[0] == 'A')
		{
			if (opt[1] == '1')
			{
				x = Read();y = Read();
				P_point(&h[x],y);
			}
			if (opt[1] == '2')
			{
				x = Read();y = Read();
                P_block(&h[x],y);
			}
			if (opt[1] == '3')
			{
				x = Read();
				All_tag += x;
			}
		}
		else if (opt[0] == 'F')
		{
            if (opt[1] == '1')
            {
				x = Read();
				Tag(&h[x]);
				printf("%d\n",(&h[x])->v + All_tag);
            }
            if (opt[1] == '2')
            {
				x = Read();
				printf("%d\n",Top(x) + All_tag);
            }
			if (opt[1] == '3')
				printf("%d\n",*st.rbegin() + All_tag);
		}
		else x = Read(),y = Read(),Unite(x,y);
	}
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("sb.out","w",stdout);
	Readin();
	Solve();
	return 0;
}
