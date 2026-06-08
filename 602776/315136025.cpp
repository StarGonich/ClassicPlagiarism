#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-5;
const ll MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
	FILE* FILE_IN = freopen("input.txt", "r", stdin);
	FILE* FILE_OUT = freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout << fixed << setprecision(3);
	
	ll n; cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	vector<ll> ns(n + 1, 0); ns[0] = 0; ns[1] = 1;
	vector<ll> ss(n + 1, 0); ss[0] = 0; ss[1] = 1;
	for (ll i = 2; i <= n; ++i) {
		ss[i] = (1 + ns[i - 2]) % MOD;
		ns[i] = (1 + 2 * ns[i - 2] + ss[i - 1]) % MOD;
	}
	ll ans = 0;
	for (ll i = 2; i < n; ++i) {
		ans = (ans + (ss[i - 1] * (1 + ns[n - i - 1])) % MOD) % MOD;
	}
	ans = (ans + (ss[n - 1]) % MOD) % MOD;
	cout << ans;
}