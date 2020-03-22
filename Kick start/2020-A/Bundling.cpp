#include <bits/stdc++.h>
using namespace std;

const int LEN = 2e6 + 10;

char a[LEN];
int n, m;
int sz, t[LEN][26], s[LEN];

void insert(char ch[]) {
    int k, len = strlen(ch), now = 0;
    for (int p = 0; p < len; ++p) {
        k = ch[p] - 'A';
        if (t[now][k] == 0)
            t[now][k] = ++sz;
        now = t[now][k];
        s[now]++;
    }
}

int ans = 0;

int dfs(int now, int depth) {
    int sum = s[now];
    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
        if (t[now][i] == 0)
            continue;
        cnt += dfs(t[now][i], depth + 1);
    }
//    printf("%d %d %d\n", sum, cnt, depth);
    sum -= cnt;
    while (sum >= m) {
        sum -= m;
        cnt += m;
        ans += depth;
    }
    return cnt;
}


void work(int T) {
    memset(t, 0, sizeof t);
    memset(s, 0, sizeof s);
    sz = 0;
    ans = 0;


    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%s", a);
        insert(a);
    }
    for (int i = 0; i < 26; ++i) {

        if (t[0][i] == 0)
            continue;

        dfs(t[0][i], 1);
    }
    printf("Case #%d: %d\n", T, ans);
}


int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        work(i);
    return 0;
}
