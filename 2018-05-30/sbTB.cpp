#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
template<typename A>
ostream & operator << (ostream &os, const vector<A> & in) {
    for (int i = 0, j = in.size(); i < j; ++i)
        os << in[i] << ' ';
    return os;
}

template <typename T> inline bool read(T &x) {
    bool f = false;
    char c;
    x = 0;
    for (c = getchar(); !isdigit(c); c = getchar()) {
        if (c == EOF) {
            return false;
        }
        if (c == '-') {
            f = true;
        }
    }
    for (; isdigit(c); c = getchar()) {
        x = (x << 1) + (x << 3) + c - '0';
    }
    if (f) {
        x = -x;
    }
    return true;
}

struct SB {
    bool operator ()(const int &x, const int &y) {
        if (x == y)
            return 0;
        return x > y;
    }
};

int main() {
    set<int, SB> s;
    s.insert(1);
    s.insert(2);
    for (auto &x: s)
        cout << x << endl;
    return 0;
}