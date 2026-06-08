#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <math.h>

typedef long long ll;
typedef long double ld;
#define pll pair<ll,ll>  
#define pii pair<int,int>  

const ld EPS = 1e-5;
using namespace std;

void solve();

int main() {
#ifndef ONLINE_JUDGE
	FILE* FILE_IN = freopen("input.txt", "r", stdin);
	FILE* FILE_OUT = freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll t = 1;
	//cin >> t;
	while (t--) solve();
}


void solve() {
	ll n; cin >> n;
	vector<ll> mins(n); for (auto& e : mins) cin >> e;
	vector<ll> dist(n); for (auto& e : dist) cin >> e;
	ll k; cin >> k;
	k--;
	ll max_l = k, max_r = k;
	ll nw_k = k;
	ll max_l_dist = min(mins[nw_k] - dist[nw_k], 1000000001ll);
	ll max_r_dist = max(mins[nw_k] + dist[nw_k], 0ll);
 	for (int i = 0; i < n; i++)
	{
		ll nmax_l = max_l;
		ll nmax_r = max_r;
		while (max_l > 0 && mins[max_l - 1] >= max_l_dist)
		{
			max_l--;
			max_l_dist = min(mins[max_l] - dist[max_l], max_l_dist);
			max_r_dist = max(mins[max_l] + dist[max_l], max_r_dist);
		}
		while (max_r < n - 1 && mins[max_r + 1] <= max_r_dist)
		{
			max_r++;
			max_l_dist = min(mins[max_r] - dist[max_r], max_l_dist);
			max_r_dist = max(mins[max_r] + dist[max_r], max_r_dist);
		}
		if (nmax_l == max_l && nmax_r == max_r) break;
	}
	ll cnt = max_r - max_l + 1;
 	cout << cnt;
}
