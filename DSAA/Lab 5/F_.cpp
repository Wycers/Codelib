#include <iostream>
#include <string>
using namespace std;

int getShort(string (&set)[1000], int &N){
	
	int shortest = 201;
	int pos;

	for (int i = 0; i < N; i++) {
		if (set[i].size() < shortest) {
			shortest = set[i].size();
			pos = i;
		}
	}
	return pos;
}

void getNext(string &P, int (&next)[200]) {

	next[0] = 0;

	for (int q = 1, k = 0; q < P.size(); q++) {
		while (k > 0 && P[q] != P[k])
			k = next[k - 1];
		if (P[q] == P[k])
			k++;
		next[q] = k;
	}
}

bool KMP(string &S, string &P, int (&next)[200]) {

	getNext(P, next);
	bool comp = false;

	for (int i = 0, j = 0; i < S.size(); i++) {
		while (j > 0 && P[j] != S[i])
			j = next[j - 1];
		if (P[j] == S[i])
			j++;
		if (j == P.size()) {
			comp = true;
			break;
		}
	}
	return comp;
}

int main() {

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		
		int N;
		cin >> N;
		string set[1000];
		
		for (int j = 0; j < N; j++) {
			cin >> set[j];
		}

		int next[200];

		int shortest = getShort(set, N);
		int size = set[shortest].size();
		bool result;
		string ans = "";
		

		for (int j = 0, k = size; k > 0; k--) {
			while (j + k < size) {
				string jk = set[shortest].substr(j, k);
				for (int f = 0; f < N; f++) {
					result = KMP(set[f], jk, next);
					if (!result) {
						break;
					}
				}
				if (result) {
					for (int x = 0; x < k; x++) {
						if (k > ans.size()) {
							ans = jk;
							break;
						}
						if (ans[x] > jk[x]) {
							ans = jk;
							break;
						}
					}
				}
				j++;
			}
			if (result)
				break;
			j = 0;
		}

		ans == "" ? cout << "Hong" << endl : cout << ans << endl;

		ans = "";
	}
	return 0;
}
