#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include<stack>
#include<deque>
#include<queue>
#define ll long long
ll mod = 1e9 + 7;
using namespace std;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

ll binPow(ll x, ll y) {
	if (y == 0) {
		return 1;
	}

	if (y == 1) {
		return x;
	}

	if (y == 2) {
		return (x * x) % mod;
	}

	if (y % 2 == 0) {
		ll t = binPow(x, y / 2);
		return (t * t) % mod;
	}

	return (x * binPow(x, y - 1)) % mod;
}

void dfs(int x, vector<vector<int>>& G, vector<int>& Mark, set<int>& ans, vector<int>& pik) {
	Mark[x] = 1;
	int f = 1;
	for (int i = 0; i < G[x].size(); ++i) {
		if (Mark[G[x][i]] == 0 && pik[G[x][i]] < pik[x]) {
			dfs(G[x][i], G, Mark, ans, pik);
			f = 0;
		}
	}
	if (f) {
		ans.insert(x);
	}
}

void f(int v, vector<int>& x, vector<int>& d, vector<int>& Mark, int& ans) {
	++ans;
	Mark[v] = 1;
	int l = v - 1;
	int r = v + 1;
	while (l >= 0) {
		if (x[v] - d[v] > x[l]) {
			break;
		}
		if (Mark[l] == 0) {
			f(l, x, d, Mark, ans);
		}
		--l;
	}
	while (r < d.size()) {
		if (x[v] + d[v] < x[r]) {
			break;
		}
		if (Mark[r] == 0) {
			f(r, x, d, Mark, ans);
		}
		++r;
	}
	
}

void solve() {
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	vector<int> d(n);
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	int k;
	cin >> k;
	--k;
	int ans = 0;

	vector<int> Mark(n);
	f(k, x, d, Mark, ans);
	cout << ans;


}




int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}
}