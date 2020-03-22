#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int K = 35;

int n, m;

int get(int len, int k) {
    if (k >= len)
        return 1;

    int x = len / k;
    int r = len - x * k;
    if (r == 0)
        return x;
    return x + 1;
}

struct Node {
    int diff, pins;
    double tar;

    Node(int d, int p) {
        diff = d;
        pins = p;
        tar = (double) d / p;
    }
};

struct cmp {
    bool operator()(const Node &a, const Node &b) { return a.tar < b.tar; }
};

priority_queue<Node, vector<Node>, cmp> q;


void work(int T) {
    while (!q.empty())
        q.pop();

    scanf("%d%d", &n, &m);
    int last;
    scanf("%d", &last);
    for (int i = 2; i <= n; ++i) {
        int XD;
        scanf("%d", &XD);
        q.push(Node(XD - last, 1));
        last = XD;
    }
    while (m--) {
        Node now = q.top();
        q.pop();
        q.push(Node(now.diff, now.pins + 1));

        printf("%d %d\n", now.diff, now.pins);
    }

    Node now = q.top();
    printf("%d %d\n", now.diff, now.pins);
    printf("Case #%d: %d\n", T, get(now.diff, now.pins));
}


int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        work(i);
    return 0;
}
