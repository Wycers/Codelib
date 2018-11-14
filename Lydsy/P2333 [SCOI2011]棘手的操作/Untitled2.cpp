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
    printf("= =!!!\n");
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
int a[N],n;
Heap *stack[N];
int All_tag = 0;

Heap* Find(Heap *k)
{
	while (k->fa != NULL)
	{
		k = k->fa;
		printf("= =\n");
	}
	return k;
}

void Tag(Heap *k)
{
	int cnt = 0;
	while (k->fa != NULL)
	{
		stack[++cnt] = k,k = k->fa;
		printf("%d\n",cnt);
	}
	while (cnt)
	{
		stack[cnt--]->DownTag();
		printf("%d\n",cnt);
	}
}

Heap *Merge(Heap *x,Heap *y)
{
    printf("= =-1\n");
    if (x == NULL)
        return y;
    if (y == NULL)
        return x;
    printf("= =0\n");
    if(x->v < y->v)
        swap(x,y);
    printf("= =1\n");
    x->DownTag();
    printf("= =2\n");
    x->r = Merge(x->r,y);
    printf("= =3\n");
    x->r->fa = x;
    printf("= =4\n");
    swap(x->l,x->r);
    printf("= =5\n");
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
    printf("= =-2\n");
    Heap *t = Merge(x->l,x->r),*f = x->fa;
    printf("= =-3\n");
    x->l = x->r = x->fa = NULL;
    printf("= =-4\n");
    if(x == f->l)
        f->l = t;
    else
        f->r = t;
    printf("= =-5\n");
    t->fa = f;
    printf("= =!\n");
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
    p->tag += val;
    p->v += val;
    Erase(p->v - val);
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

		a[i] = Read(),h[i].v = a[i];
		st.insert(a[i]);
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
				printf("= =");
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
				printf("%d\n",*--st.find(1000000000) + All_tag);
		}
		else x = Read(),y = Read(),Unite(x,y);
		printf("Finished\n");
	}
}

int main()
{
	Readin();
	Solve();
	return 0;
}
