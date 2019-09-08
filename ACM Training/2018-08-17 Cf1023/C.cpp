#include <cstdio>
using namespace std;
const int N = 2e5 + 10;
int n, k, top = 0;
char str[N], st[N];
int main()
{
    scanf("%d%d%s", &n, &k, str);
    int cnt = (n - k) / 2;
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == '(')
            st[++top] = '(';
        else
        {
            if (cnt)
            {
                --cnt;
                --top;
            }
            else
                st[++top] = ')';
        }
    }
    for (int i = 1; i <= k; ++i)
        printf("%c", st[i]);
    return 0;
}