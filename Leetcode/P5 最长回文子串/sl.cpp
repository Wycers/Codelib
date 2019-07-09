const int N = 1010;
const int ALP = 128;
struct PAM
{
    int next[N][ALP], fail[N], num[N];
    int len[N], s[N];
    int last, n, p;

    int newnode(int w)
    {
        for (int i = 0; i < ALP; i++)
            next[p][i] = 0;
        num[p] = 0;
        len[p] = w;
        return p++;
    }
    void init()
    {
        p = 0;
        newnode(0);
        newnode(-1);
        last = 0;
        n = 0;
        s[n] = -1;
        fail[0] = 1;
    }
    int get_fail(int x)
    {
        while (s[n - len[x] - 1] != s[n])
            x = fail[x];
        return x;
    }
    void add(int c)
    {
        s[++n] = c;
        int cur = get_fail(last);
        if (!next[cur][c])
        {
            int now = newnode(len[cur] + 2);
            fail[now] = next[get_fail(fail[cur])][c];
            next[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = next[cur][c];
    }
} pam;
class Solution
{
public:
    string longestPalindrome(string s)
    {

        pam.init();
        int ans_len = 0, ans_index = -1;
        for (int i = 0, len = s.length(); i < len; ++i)
        {
            pam.add(s[i]);
            int t = pam.len[pam.last];
            if (t > ans_len)
            {
                ans_len = t;
                ans_index = i;
            }
        }
        return s.substr(ans_index - ans_len + 1, ans_len);
    }
};
