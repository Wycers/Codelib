#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct gift{
	int K, L, ti;
	gift(int k, int l, int t) {
		K = k;
		L = l;
		ti = t;
	}
	~gift() {}
	friend bool operator < (gift gift1, gift gift2) {
		if (gift1.L < gift2.L || gift1.L == gift2.L && gift1.ti > gift2.ti)
			return true;
		return false;
	}
};

int num[1 << 20], ti[1 << 20], input[ 1 << 20];
priority_queue<gift> pocket;
int main() {

freopen("test.in", "r", stdin);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0;i < T;i++) {
		
		int M, N;
		cin >> M >> N;
        while (!pocket.empty())
            pocket.pop();
        memset(num, 0, sizeof num);
        memset(ti, 0, sizeof ti);

		int count = 0, size = 0;

		for (int j = 0;j < N;j++)
			cin >> input[j];

		for (int j = 0;j < N;j++) {
			if (size < M) {
				if (num[input[j]] == 0) {
					ti[input[j]] = j + 1;
					size++;
				}
				num[input[j]]++;
				gift sample(input[j], num[input[j]], ti[input[j]]);
				pocket.push(sample);
			}
			else {
				if (num[input[j]] == 0) {
					while (ti[pocket.top().K] == 0) {
						pocket.pop();
					}
					num[pocket.top().K] = 0;
					ti[pocket.top().K] = 0;
					pocket.pop();
					count++;
					num[input[j]]++;
					ti[input[j]] = j + 1;
					gift sample(input[j], num[input[j]], ti[input[j]]);
					pocket.push(sample);
				}
				else {
					num[input[j]]++;
					gift sample(input[j], num[input[j]], ti[input[j]]);
					pocket.push(sample);
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}