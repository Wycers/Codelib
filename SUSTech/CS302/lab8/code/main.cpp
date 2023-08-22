#pragma GCC optimize ("O3")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

inline int read() {
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || '9' < ch) {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

vector<int> l, r;

int main() {
    int s = read();
    int m = read();
    int n = read();


    for (int i = 0; i < n; ++i) {
        int now = read();
        if (now <= s) {
            l.push_back(now);
        } else {
            r.push_back(now);
        }
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

//    if (!l.empty() && s != l.back()) {
        printf("%d ", s);
//    }

    for (auto i = l.rbegin(); i != l.rend(); ++i) {
        printf("%d ", *i);
    }
    for (auto i = r.rbegin(); i != r.rend(); ++i) {
        printf("%d ", *i);
    }
    puts("");


    int distance = 0;
    if (!l.empty()) {
        distance += s - *l.begin();
        s = l[0];
    }
    if (!r.empty()) {
        distance += *r.rbegin() - s;
        s = *r.rbegin();

        distance += s - *r.begin();
        s = *r.begin();
    }
    printf("%d\n", distance);
    return 0;
}