#define _USE_MATH_DEFINES
#include <iostream>
#include <ios>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>

#include <queue>
using namespace std;

#define ll long long
#define sortt(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define pb push_back

struct fenwick {
	vector<int> t;
	int n;

	fenwick(int n_) : n(n_) {
		t.assign(n, 0);
	}

	int get(int i) {
		int sum = 0;
		for (; i >= 0; i = (i & (i + 1)) - 1) sum += t[i];
		return sum;
	}

	void add(int i, int dif) {
		for (; i < n; i = i | (i + 1)) t[i] += dif;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

const ll inf = 2e18;

vector<pair<pair<ll, ll>, ll>> g[1000][101];
pair<ll, ll> from[1000][101];
ll dp[1000][101];

void solve() {
	ll n, m;
	cin >> n >> m;

	vector<ll> cost(n);
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		for (int level = cost[i] + 1; level <= 100; level++) {
			g[i][level].pb({ {i, cost[i]}, 0 });
		}
	}

	for (int i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		for (int level = 0; level <= 100; level++) {
			g[u][level].pb({ {v, level}, w});
			g[v][level].pb({ {u, level}, w});
		}
	}

	for (int i = 0; i < n; i++) {
		for (int c = 0; c <= 100; c++) dp[i][c] = inf;
	}
	
	priority_queue<tuple<ll, pair<ll, ll>, pair<ll, ll>>> q;
	q.push({ 0, {0, cost[0]}, {-1, -1} });
	while (q.size()) {
		auto p = q.top(); q.pop();

		ll dpwas = -get<0>(p);
		pair<ll, ll > nowpair = get<1>(p);
		ll costnow = nowpair.second;
		ll posnow = nowpair.first;

		pair<ll, ll> frompair = get<2>(p);

		if (dp[posnow][costnow] != inf) continue;
		from[posnow][costnow] = frompair;
		dp[posnow][costnow] = dpwas;

		for (auto& to : g[posnow][costnow]) {
			pair<ll, ll> topair = to.first;
			ll tow = to.second;

			ll costgo = dpwas + costnow * tow;
			q.push({ -costgo, topair, nowpair });
		}
	}

	pair<ll, ll> now;
	ll costnow = inf;
	for (int c = 0; c <= 100; c++) {
		if (dp[n - 1][c] < costnow) {
			costnow = dp[n - 1][c];
			now = { n - 1, c };
		}
	}

	if (costnow == inf) {
		cout << -1 << endl;
		return;
	}

	cout << dp[now.first][now.second] << "\n";

	ll filled = 0;
	vector<pair<ll, ll>> ans;
	ans.pb({ n, 0 });
	while (now.first != 0) {
		pair<ll, ll> parent = from[now.first][now.second];
		if (now.second != parent.second) {
			ll fillnow = filled / now.second;
			ans[ans.size() - 1].second = fillnow;
			filled = 0;
		}
		else ans.pb({ parent.first + 1, 0 });

		filled += dp[now.first][now.second] - dp[parent.first][parent.second];
		now = parent;
	}
	ans[ans.size() - 1].second = filled / now.second;


	rev(ans);
	cout << ans.size() << endl;
	for (auto p : ans) {
		cout << p.first << " " << p.second << "\n";
	}	
}

int main()
{
	cout.tie(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(10);
	solve();
}
