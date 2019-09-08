#include <cstdio>
using namespace std;
const int N = 1e4 + 10;
int read() {
    int x = 0, f = -1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

int n, a[N];

int dfs(int k) {
    for (int i = 1; i <= n; ++i) {
        
    }
}

void solve() {
    n = read();
}

int main() {
    for (int T = read(); T--; ) 
        solve();
    return 0;
}