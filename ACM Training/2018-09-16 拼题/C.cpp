//while (clock()<=4.9*CLOCKS_PER_SEC)
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr db PI = acos(-1), eps = 1e-8;
constexpr ll mod = (ll)1e9 + 7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);
    ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) {
        if (b & 1) {
            res = res * a % mod;
        }
    }
    return res;
}
const int N = 10005;
struct command {
    char op[5];
    int x, y, tp;

    void read() {
        scanf("%s", op);
        scanf("%d", &x);
        if (op[0] == 'b') {
            scanf("%d", &y);
        }
        if (strcmp(op, "add") == 0) {
            tp = 1;
        } else if (strcmp(op, "beq") == 0) {
            tp = 2;
        } else if (strcmp(op, "bne") == 0) {
            tp = 3;
        } else if (strcmp(op, "blt") == 0) {
            tp = 4;
        } else {
            tp = 5;
        }
    }
};

command commands[N];

bool state_used[N][258];
int n;
void gao() {
    memset(state_used, 0, sizeof(state_used));
    int now_comm = 1;
    unsigned char now_reg = 0;
    for (; ;++now_comm) {
        if (state_used[now_comm][now_reg]) {
            puts("No");
            return;
        }
        state_used[now_comm][now_reg] = true;
        if (commands[now_comm].tp == 1) {
            now_reg += (unsigned char) commands[now_comm].x;
        } else if (commands[now_comm].tp == 2) {
            if ((int) now_reg == commands[now_comm].x) {
                now_comm = commands[now_comm].y - 1;
            }
        } else if (commands[now_comm].tp == 3) {
            if ((int) now_reg != commands[now_comm].x) {
                now_comm = commands[now_comm].y - 1;
            }
        } else if (commands[now_comm].tp == 4) {
            if ((int) now_reg < commands[now_comm].x) {
                now_comm = commands[now_comm].y - 1;
            }
        } else {
            if ((int) now_reg > commands[now_comm].x) {
                now_comm = commands[now_comm].y - 1;
            }
        }
        if (now_comm + 1 > n) {
            puts("Yes");
            return;
        }
    }
}

int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            commands[i].read();
        }
        gao();
    }
    return 0;
}
