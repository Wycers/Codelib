#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, a[N];

int work() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    sort(a, a + n);
    int sum = 0;
    for (int i = 0 ; i < n; ++i)
        if ((sum += a[i]) > m) {
            return i;
        }
    return n;
}


int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        printf("Case #%d: %d\n", i, work());
    return 0;
}
