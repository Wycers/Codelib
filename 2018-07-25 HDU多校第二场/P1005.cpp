int main() {
#ifdef Wavator
    freopen("C:\\Users\\wavator\\Desktop\\1.txt", "w", stdout);
#endif
    static const int MOD = 51;
    vector<vector<int> > ans(2000, vector<int>(2000, 0));
    rep(i, 0, MOD) {
        rep(j, 0, MOD) {
            int now=j;
            rep(k, 0, MOD) {
                int x = i*MOD+j;
                int y = k*MOD+now;
                (now+=i)%=MOD;
                if(x < 2000 && y < 2000)ans[x][y] = 1;
            }
        }
    }
    puts("2000");
    for (const auto &row: ans) {
        for (const auto &c: row) {
            putchar(c+48);
        }
        putchar(10);
    }
    return 0;
}