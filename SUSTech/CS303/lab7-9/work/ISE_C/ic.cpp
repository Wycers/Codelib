#include <cstdio>
#include <queue>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, m;
vector<int> seeds;
struct Edge {
	int to, next;
	double w;
} edge[M];
int head[N], cnt = 0;
void insert(int u, int v, double w) {
	edge[++cnt] = (Edge){v, head[u], w};
	head[u] = cnt;
}
void readin(char* network, char* seed) {
	freopen(network, "r", stdin);
	scanf("%d%d", &n, &m);
	int u, v; double w;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%lf", &u, &v, &w);
		insert(u - 1, v - 1, w);
	}
	fclose(stdin);

	freopen(seed, "r", stdin);
	while (~scanf("%d", &u))
		seeds.push_back(u - 1);
	fclose(stdin);
}

queue<int> q, tmp;
bool acted[N];
int _IC() {
	q = tmp;
	memset(acted, false, sizeof(acted));
	for (const int &i : seeds) {
		q.push(i);
		acted[i] = 1;
	}

	while (!q.empty()) {
		int u = q.front();
		for (int i = head[u]; i; i = edge[i].next) {
			int v = edge[i].to;
			if (acted[v])
				continue;
			if ((double)(rand() % 1000) < edge[i].w * 1000.0) {
				q.push(v);
				acted[v] = true;
			}
		}
		q.pop();
	}
	int res = 0;
	for (int i = 0; i < n; ++i)
		res += acted[i];
	return res;
}
extern "C" {
	int IC(int seed) {
		srand(seed);
		return _IC();
	}
	void init(char* network, char* seed) {
		while (!tmp.empty())
			tmp.pop();
		memset(head, 0, sizeof head);
		cnt = 0;
		readin(network, seed);
	}
}
