#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 3e3 + 10;
const int M = 3e3 + 10;

int n, cnt;
char ch[N][N];
int cnth[N][30];
int cntv[N][30];
void readin()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%s", ch[i]);
    memset(cnth, 0, sizeof(cnth));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (ch[i][j] != '?')
                cnth[i][ch[i][j] - 'a']++;
            else 
                cnth[i][26]++;

    memset(cntv, 0, sizeof(cntv));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (ch[j][i] != '?')
                cntv[i][ch[j][i] - 'a']++;
            else 
                cntv[i][26]++;
}
deque<int> q;
int tag[2 * N]; char type[2 * N], color[2 * N];
bool check(char t, int tag, char c)
{
    if (t == 'h')
    {
        if (c == '?')
            return cnth[tag][26] == n;
        for (int i = 0; i < n; ++i)
            if (ch[tag][i] != '?' && ch[tag][i] != c)
                return false;
        return true;
    }
    else
    {
        if (c == '?')
            return cntv[tag][26] == n;
        for (int i = 0; i < n; ++i)
            if (ch[i][tag] != '?' && ch[i][tag] != c)
                return false;
        return true;
    }
    return false;
}
bool h[N], v[N];
inline void push(char t, int num, char c)
{
    ++cnt;
    type[cnt] = t;
    color[cnt] = c;
    tag[cnt] = num;
    q.push_back(cnt);
}

void solve()
{
    cnt = 0;
    while (cnt < 2 * n)
    {
        for (int i = 0; i < n; ++i)
            if (!h[i] && check('h', i, '?'))
                {
                    push('h', i, 'a');
                    h[i] = true;
                }
        for (int i = 0; i < n; ++i)
            if (!v[i] && check('v', i, '?'))
                {
                    push('v', i, 'a');
                    v[i] = true;
                } 

        for (int i = 0; i < n; ++i)
        {
            if (h[i])
                continue;
            bool flag = true;
            char now = '?';
            for (int j = 0; j < 26; ++j)
                if (cnth[i][j] > 0)
                {
                    now = j + 'a';
                    break;
                }
            if (now == '?')
                continue;
            if (check('h', i, now))
            {
                push('h', i, now);
                h[i] = true;

                for (int j = 0; j < n; ++j)
                {
                    int x = ch[i][j] - 'a';
                    if (ch[i][j] == '?')
                        x = 26;
                    cntv[j][x]--; cntv[j][26]++;
                    ch[i][j] = '?';
                }
                cnth[i][26] = n;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (v[i])
                continue;
            bool flag = true;
            char now = '?';
            for (int j = 0; j < 26; ++j)
                if (cntv[i][j] > 0)
                {
                    now = j + 'a';
                    break;
                }
            if (now == '?')
                continue;
            if (check('v', i, now))
            {
                push('v', i, now);
                v[i] = true;

                for (int j = 0; j < n; ++j)
                {
                    
                    int x = ch[j][i] - 'a';
                    if (ch[j][i] == '?')
                        x = 26;
                    cnth[j][x]--; cnth[j][26]++;
                    ch[j][i] = '?';
                }
                cntv[i][26] = n;
            }
        }
        
    }
    
    while (!q.empty())
    {
        int t = q.back(); q.pop_back();
        printf("%c %d %c\n", type[t], tag[t] + 1, color[t]);
    }
}
int main()
{
    readin();
    solve();
    return 0;
}