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
		insert(u, v, w);
	}
	fclose(stdin);

	freopen(seed, "r", stdin);
	while (~scanf("%d", &u))
		seeds.push_back(u);
	fclose(stdin);
}

vector<int> vec[2], tmp;
bool acted[N];
double threshold[N];
int _LT() {
	vec[0].clear();
	vec[1].clear();
	memset(acted, false, sizeof(acted));
	for (int i = 0; i < n; ++i)
		threshold[i] = (double)(rand() % 1000) / 1000.0;
	int now = 0;
	for (const int &i : seeds) {
		vec[now].push_back(i);
	}

	while (!vec[now].empty()) {
		for (const int &u : vec[now]) {
			acted[u] = true;
			for (int i = head[u]; i; i = edge[i].next) {
				int v = edge[i].to;
				if (acted[v])
					continue;
				threshold[v] -= edge[i].w;
			}
		}
		for (const int &u : vec[now]) {
			for (int i = head[u]; i; i = edge[i].next) {
				int v = edge[i].to;
				if (acted[v] || threshold[v] > 0)
					continue;
				vec[now ^ 1].push_back(v);
				acted[v] = true;
			}
		}
		vec[now].clear();
		now ^= 1;
	}
	int res = 0;
	for (int i = 0; i < n; ++i)
		res += acted[i];
	return res;
}
extern "C" {
	int LT(int seed) {
		srand(seed);
		return _LT();
	}
	void init(char* network, char* seed) {
		while (!tmp.empty())
			tmp.pop_back();
		memset(head, 0, sizeof head);
		cnt = 0;
		readin(network, seed);
	}
}
