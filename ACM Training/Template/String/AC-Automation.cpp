#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
struct node {
    node *next[26];
    node *fail;
    int cnt;
} *root, *newnode;
void insert(char *str)
{
    node *p = root;
    for (int i = 0, len = strlen(str); i < len; ++i)
    {
        int ch = str[i] - 'a';
        if (p->next[ch] == NULL)
        {
            newnode = (node *)malloc(sizeof(node));
            for (int j = 0; j < 26; ++j)
                newnode->next[j] = 0;
            newnode->cnt = 0; newnode->fail = 0;
            p->next[ch] = newnode;
        }
        p = p->next[ch];
    }
    ++p->cnt;
}
queue<node*> q;
void getfail()
{
    while (!q.empty())
        q.pop();
    q.push(root);
    while (!q.empty())
    {
        node* now = q.front(); q.pop();
        for (int i = 0; i < 26; ++i)
        {
            if (!now->next[i])
                continue;
            if (now == root)
                now->next[i]->fail = root;
            else 
            {
                node *p;
                for (p = now->fail; p; p = p->fail)
                    if (p->next[i])
                    {
                        now->next[i]->fail = p->next[i];
                        break;
                    }
                if (p == NULL)
                    now->next[i]->fail = root;
            }
            q.push(now->next[i]);
        }
    }
}
int ans;
void ac_automation(char *str)
{
    node *p = root;
    for (int i = 0, len = strlen(str); i < len; ++i)
    {
        int ch = str[i] - 'a';
        while (!p->next[ch] && p != root)
            p = p->fail;
        p = p->next[ch];
        if (!p)
            p = root;
        for (node *now = p; now != root; now = now->fail)
        {
            if (now->cnt < 0)
                break;
            ans += now->cnt;
            now->cnt = -1; 
        }
    }
}
char str[N];
int main()
{
    freopen("test.in", "r", stdin);
    int n, T; scanf("%d",&T);
    while(T--)
    {
        root = (node *)malloc(sizeof(node));
        for (int j = 0; j < 26; j++)
            root->next[j] = 0;
        root->fail = 0;
        root->cnt = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", str);
            insert(str);
        }
        scanf("%s", str);
        ans = 0;
        getfail();
        ac_automation(str);
        printf("%d\n", ans);
    }
    return 0;
}