#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 5e4 + 10;
const int Inf = 0x3f3f3f3f;
const double Alpha = 0.7;
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
    node *ch[2]; int lsize, key, size;
    bool exist;
    bool Balance()
    {
        return (ch[0]->lsize <= lsize * Alpha && ch[1]->lsize <= lsize * Alpha);
    }
    void Update()
    {
        size = exist + ch[0]->size + ch[1]->size;
        lsize = 1 + ch[0]->lsize + ch[1]->lsize;
    }
};
struct ScapeGoatTree
{
    node a[N];
    node *bc[N]; int bc_top;
    node *null, *tail, *root; 
    void Init()
    {
        tail = a;
        null = tail++;
        null->ch[0] = null->ch[1] = null;
        null->size = null->key = null->lsize = 0;
        root = null;
        bc_top = 0;
    }
    node *newNode(int key)
    {
        node *p;
        if (bc_top)
            p = bc[bc_top--];
        else
            p = tail++;
        p->ch[0] = p->ch[1] = null;
        p->key = key;
        p->size = p->lsize = 1;
        p->exist = true;
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
            bc[++bc_top] = p;
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
    node **Insert(node *&p, int val)
    {
        if (p == null)
        {
            p = newNode(val);
            return &null;
        }
        ++p->size; ++p->lsize;
        node **res = Insert(p->ch[val >= p->key], val);
        if (!p->Balance())
            res = &p;
        return res;
    }
    void Insert(int key)
    {
        node **p = Insert(root, key);
        if(*p != null)
            Rebuild(*p);
    }
    void Del(node *p, int id)
    {
        p->size--;
        if (p->exist && id == p->ch[0]->size + 1)
        {
            p->exist = false;
            return;
        }
        if (id <= p->ch[0]->size + p->exist)
            Del(p->ch[0], id);
        else
            Del(p->ch[1], id - p->ch[0]->size - p->exist);
    }
    int Getrank(int val)
    {
        node *now = root;
        int ans = 1;
        while (now != null)
        {
            if (now->key < val)
                ans += now->ch[0]->size + now->exist;
            now = now->ch[now->key < val];
        }
        return ans;
    }
    int GetKth(int k)
    {
        node *now = root;
        while (now != null)
        {
            if (now->exist && k == now->ch[0]->size + 1)
                return now->key;
            if (now->ch[0]->size < k)
            {
                k -= now->ch[0]->size + now->exist;
                now = now->ch[1];
            }
            else
                now = now->ch[0];
        }
        return Inf;
    }
    void Del(int val)
    {
        Del(root, val);
        if (root->size < Alpha * root->lsize)
            Rebuild(root);
    }
} Tree;
//Code
int main()
{
    int n = read(), x, pre, suf, self, res;
    Tree.Init();
    ll ans = 0;
    x = read();
    ans += x;
    Tree.Insert(x);
    for (int i = 2; i <= n; ++i)
    {
    	x = read();
        pre = Tree.GetKth(Tree.Getrank(x) - 1);
        self = Tree.GetKth(Tree.Getrank(x));
        suf = Tree.GetKth(Tree.Getrank(x + 1));
        if (self == x)
            pre = suf = self;
        res = min(abs(x - pre), abs(x - suf));
        ans += res;
        Tree.Insert(x);
    }
    cout << ans << endl;
    return 0;
}
