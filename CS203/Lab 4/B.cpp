#include <cstdio>
#include <cstring>
const int N = 3e4 + 10;
int len, top;
char str[N], st[N];
bool solve()
{
    scanf("%d", &len);
    scanf("%s", str);
    top = 0;
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            st[++top] = str[i];
        else 
        {
            if (top == 0)
            	return false;
            if (str[i] == ')' && st[top] != '(')
                return false;
            if (str[i] == ']' && st[top] != '[')
                return false;
            if (str[i] == '}' && st[top] != '{')
                return false;
            --top;
        }
    }
    if (top)
    	return false;
    return true;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        puts(solve() ? "YES" : "NO");
    return 0;
}