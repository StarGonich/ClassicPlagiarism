#include <bits/stdc++.h>
//#define int long long
using namespace std;

int main() {
	int n;
	int t;
	cin >> n >> t;
	vector<pair<int, int>> v(n);
	for (auto & [a, b] : v) {
		cin >> a >> b;
	}
	queue<pair<int, int>> q;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i].second - v[i].first;

		q.push(v[i]);
		while (q.front().first < v[i].second - 3600) {
			auto [l, r] = q.front();
			if (v[i].second - 3600 <= r) {
				q.front().first = v[i].second - 3600;
				sum -= v[i].second - 3600 - l;
			}
			else {
				sum -= r - l;
				q.pop();
			}
		}
		if (sum > t) {
			int l = v[i].first;
			int pi = i;
			int psum = 0;
			for (int j = l; j > l - 3600; j--) {
				if (j < v[pi].first) {
					pi--;
				}
				if (pi < 0) {
					break;
				}
				if (j < v[pi].second) {
					psum++;
				}
			}
			int j = l - 3600 + 1;
			pi = max(pi, 0);
			while (psum <= t) {
				if (v[pi].second <= j) {
					pi++;
				}
				if (v[pi].first <= j) {

				}
				else {
					psum++;
				}
				j++;
			}
//			cout << psum << "\n";
			cout << max(0, j);
			return 0;
		}
	}
	cout << -1;
    return 0;
}
/*3
1000
0 100
5000 5300
6000 7000

*/
