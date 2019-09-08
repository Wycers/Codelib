#include <cstdio>
int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

int f[40];
int main() {
    f[1] = 1; f[2] = 2;
    for (int i = 3; i <= 30; ++i) {
        f[i] = 0;
        for (int j = 1; j < i; ++j)
            f[i] += f[j];
    }
    for (int T = read(); T; T--) {
        int n = read();
        printf("%d\n", f[n]);
    }
    return 0;
}