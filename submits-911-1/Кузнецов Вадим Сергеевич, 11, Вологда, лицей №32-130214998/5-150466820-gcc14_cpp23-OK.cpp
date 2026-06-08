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
			for (int j = 0; j < m; j++) {
				int sum = 0;
				for (int di = -1; di <= 1; di++) {
					for (int dj = -1; dj <= 1; dj++) {
						if (i + di < 0) continue;
						if (i + di >= n) continue;
						if (j + dj < 0) continue;
						if (j + dj >= m) continue;
						if (di == 0 && dj == 0) continue;
						if (v[i + di][j + dj] == 0) continue;
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
			}
		}
		if (p.v == v) {
			p.ind = -2;
		}
		return p;
	}
};
vector<bool> used(100);
void dfs(int i, vector<int> & ans) {
	if (used[i]) {
		return;
	}
	used[i] = 1;
	if (ans[i] == -2) {
		cout << i + 1<< " ";
		return;
	}
	dfs(ans[i], ans);
	cout << i + 1 << " ";
}

int main() {
//	freopen("in.txt", "r", stdin);
	int k;
	cin >> k;
	cin >> n >> m;
	map<vector<vector<int>>, int> mp;
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
		mp[p[i].v] = i + 1;
		p[i].ind = i;
//		cout << p[i].nest() << "\n";
	}
	vector<int> ans(k, -2);
	for (int i = 0; i < k; i++) {
		p[i] = p[i].next();
		while (mp[p[i].v] == 0) {
			mp[p[i].v] = -1;
			p[i] = p[i].next();
		}
		ans[i] = mp[p[i].v] - 1;
	}
	vector<int> rev(k, -2);
	for (int i = 0; i < k; i++) {
		if (ans[i] != -2 && ans[i] != i) {
			rev[ans[i]] = i;
		}
	}
//	for (int i = 0; i < k; i++) {
//		cout << ans[i] << "\n";
//	}
//	for (int i = 0; i < k; i++) {
//		cout << rev[i] << "\n";
//	}
	for (int i = 0; i < k; i++) {
		dfs(i, rev);
	}
    return 0;
}
/*3
1000
0 100
5000 5300
6000 7000

*/
