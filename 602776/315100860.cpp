#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <memory>
#include <stack>
using namespace std;
using ll = long long;
using ld = long double;
#define debug(x) std::cerr << __FUNCTION__ << ":" << __LINE__ << " " << #x << " = " << x << '\n';
const ll INF = 4e18;
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	vector<ll> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	set<ll> will;
	ll k;
	cin >> k;
	k--;
	will.insert(k);
	ll luk = k;
	ll ruk = k;
	while (will.size()) {
		ll now = *will.begin();
		will.erase(now);
		ll dist = d[now];
		while (luk - 1 >= 0 && ar[luk - 1] >= ar[now] - dist) {
			luk--;
			will.insert(luk);
		}
		while (ruk + 1 < n && ar[ruk + 1] <= ar[now] + dist) {
			ruk++;
			will.insert(ruk);
		}
	}
	cout << ruk - luk + 1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1;
	//cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}