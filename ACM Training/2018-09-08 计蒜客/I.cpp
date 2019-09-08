#include <cstdio>
#include <cstring>
const int M = 2e5 + 10;
int m, n;
char str[M];
bool dig[M * 4];
void set(int p, char ch)
{
    int c;
    if (ch >= 'a')
        c = ch - 'a' + 10;
    else if (ch >= 'A')
        c = ch - 'A' + 10;
    else 
        c = ch - '0';
    switch (c) {
        case  0: dig[p] = 0, dig[p + 1] = 0, dig[p + 2] = 0, dig[p + 3] = 0; break;
        case  1: dig[p] = 0, dig[p + 1] = 0, dig[p + 2] = 0, dig[p + 3] = 1; break;
        case  2: dig[p] = 0, dig[p + 1] = 0, dig[p + 2] = 1, dig[p + 3] = 0; break;
        case  3: dig[p] = 0, dig[p + 1] = 0, dig[p + 2] = 1, dig[p + 3] = 1; break;
        case  4: dig[p] = 0, dig[p + 1] = 1, dig[p + 2] = 0, dig[p + 3] = 0; break;
        case  5: dig[p] = 0, dig[p + 1] = 1, dig[p + 2] = 0, dig[p + 3] = 1; break;
        case  6: dig[p] = 0, dig[p + 1] = 1, dig[p + 2] = 1, dig[p + 3] = 0; break;
        case  7: dig[p] = 0, dig[p + 1] = 1, dig[p + 2] = 1, dig[p + 3] = 1; break;
        case  8: dig[p] = 1, dig[p + 1] = 0, dig[p + 2] = 0, dig[p + 3] = 0; break;
        case  9: dig[p] = 1, dig[p + 1] = 0, dig[p + 2] = 0, dig[p + 3] = 1; break;
        case 10: dig[p] = 1, dig[p + 1] = 0, dig[p + 2] = 1, dig[p + 3] = 0; break;
        case 11: dig[p] = 1, dig[p + 1] = 0, dig[p + 2] = 1, dig[p + 3] = 1; break;
        case 12: dig[p] = 1, dig[p + 1] = 1, dig[p + 2] = 0, dig[p + 3] = 0; break;
        case 13: dig[p] = 1, dig[p + 1] = 1, dig[p + 2] = 0, dig[p + 3] = 1; break;
        case 14: dig[p] = 1, dig[p + 1] = 1, dig[p + 2] = 1, dig[p + 3] = 0; break;
        case 15: dig[p] = 1, dig[p + 1] = 1, dig[p + 2] = 1, dig[p + 3] = 1; break;
    }
}
struct trie
{
    int ch[3000][2], p, root; char v[3000];
    void init()
    {
        p = 0;
        root = p++;
        memset(ch, 0, sizeof ch);
        memset(v, 0, sizeof v);
    }
    void insert(char *str, int value)
    {
        int now = root;
        for (int i = 0, len = strlen(str); i < len; ++i)
        {
            int c = str[i] - '0';
            if (ch[now][c] == 0)
                ch[now][c] = p++;
            now = ch[now][c];
        }
        v[now] = value;
    }
    int match(int &now, int c)
    {
        now = ch[now][c];
        if (v[now])
            return v[now];
        return -1;
    }
} tr;
void solve()
{
    scanf("%d%d", &m, &n);
    tr.init();
    int cha; char word[15];
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%s", &cha, word);
        tr.insert(word, cha);
    }
    scanf("%s", str);
    for (int i = 0, len = strlen(str); i < len; ++i)
        set(i * 4, str[i]);

    int now = 0;
    for (int i = 0, len = 4 * strlen(str); i < len; i += 9)
    {
        int cnt = 0;
        if (i + 8 >= len)
            break;
        for (int j = 0; j < 8; ++j)
            if (dig[i + j])
                ++cnt;
        if (((cnt & 1) == 0 && dig[i + 8] == 1) || ((cnt & 1) == 1 && dig[i + 8] == 0))
        {
            for (int j = 0; j < 8; ++j)
                dig[now++] = dig[i + j];
        }
    }


    int node = tr.root, cnt = 0;
    for (int i = 0; i < now; ++i)
    {
        int v = tr.match(node, dig[i]);
        if (v != -1)
        {
            ++cnt;
            node = tr.root;
            printf("%c", v);
        }
        if (cnt >= m)
            break;
    }
    puts("");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}