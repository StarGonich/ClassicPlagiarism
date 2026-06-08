#include <bits/stdc++.h>
//#define int long long
using namespace std;

	int n, m;

struct Pole {
	vector<vector<int>> v;
	int ind;
	int cnt;
	Pole (int n, int m) {
		v = vector<vector<int>>(n, vector<int>(m));
		ind = -1;
		cnt = 0;
	}
	Pole next() {
		Pole p(0, 0);
		p.v = v;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int sum = 0;
				for (int di = -1; di <= 1; di++) {
					for (int dj = -1; dj <= 1; dj++) {
						if (i + di < 0) continue;
						if (i + di >= n) continue;
						if (j + dj < 0) continue;
						if (j + dj >= m) continue;
						if (i == 0 && j == 0) continue;
						if (!v[i + di][j + dj]) continue;
						sum++;
					}
				}
				if (v[i][j]) {
					if (sum < 2 || sum > 3) {
						p.v[i][j] = 0;
					}
				}
				else {
					if (sum == 3) {
						p.v[i][j] = 1;
					}
				}
				if (p.v[i][j]) {
					p.cnt++;
				}
				cout << p.v[i][j] << " ";
			}
			cout << "\n";
		}
		if (p.v == v) {
			p.ind = -2;
		}
		return p;
	}
	int nest() {
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int sum = 0;
				for (int di = -1; di <= 1; di++) {
					for (int dj = -1; dj <= 1; dj++) {
						if (i + di < 0) continue;
						if (i + di >= n) continue;
						if (j + dj < 0) continue;
						if (j + dj >= m) continue;
						if (di == 0 && dj == 0) continue;
						if (!v[i + di][j + dj]) continue;
						sum++;
					}
				}
				if (v[i][j]) {
					if (sum < 2 || sum > 3) {
						res++;
					}
				}
				else {
					if (sum == 3) {
						res++;
					}
				}
			}
		}
		return res;
	}
	bool operator<(Pole p) {
		if (nest() == p.nest()) {
			return cnt > p.cnt;
		}
		return nest() > p.nest();
	}
};

int main() {
//	freopen("in.txt", "r", stdin);
	int k;
	cin >> k;
	cin >> n >> m;
	vector<Pole> p(k, Pole(n, m));
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			for (int q = 0; q < m; q++) {
				cin >> p[i].v[j][q];
				if (p[i].v[j][q]) {
					p[i].cnt++;
				}
			}
		}
		p[i].ind = i;
//		cout << p[i].nest() << "\n";
	}
//	for (int i = 0; i < n; i++) {
//		Pole p0 = p[i];
//		Pole p1 = p0.next();
//		Pole p2 = p0.next();
//		if (p[i].cnt <= p[i].next().cnt && p[i].next().cnt != p[i].next().next().cnt) {
//			p[i].cnt = 1e9;
//		}
//	}
	sort(p.begin(), p.end());
	for (int i = 0; i < k; i++) {
		cout << p[i].ind + 1 << " ";
	}
    return 0;
}
/*3
1000
0 100
5000 5300
6000 7000

*/
