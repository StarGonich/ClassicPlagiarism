#include <bits/stdc++.h>
//#define int long long
using namespace std;

const __int128 ONE = 1;

int main() {
	long long n, k;
	cin >> n >> k;
	vector<long long> d;
	d.push_back(n);
	d.push_back(1);
	for (long long j = 2; j * j <= n; j++) {
		if (n % j == 0) {
			d.push_back(j);
			d.push_back(n / j);
		}
	}
	k += n;
	long long ans = 1e13;
	long long ans2 = 1e13;
	for (auto g : d) {
		long long b = n / g + 1;
		if (ONE * g * b <= k * ONE) {
			if (ONE * n * b < ONE * ans2) {
				ans = g * b;
				ans2 = n * b;
			}
		}
	}
	cout << ans << "\n";
    return 0;
}
/*3
1000
0 100
5000 5300
6000 7000

*/
