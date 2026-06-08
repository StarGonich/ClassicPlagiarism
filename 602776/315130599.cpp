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
ll opt(ll a) {
	ll opt = 1;
	for (int i = 2; i <= a; i++) {
		ll nxt = i;
		ll pr = 0;
		ll aa = a;
		for (int j = 0; j < 3; j++) {
			aa -= (pr + nxt);
			pr += nxt;
			nxt = pr + nxt;
		}
		if (aa >= (nxt + pr)) {
			opt = i;
		}
	}
	return opt;
}
void solve() {
	std::random_device r;
	std::default_random_engine e(r());
	std::uniform_int_distribution<int> dist(0, 1);
	ll now = 210;

	vector<ll> tt = { 0,1 };
	ll cnt = 0;
	ll all = 0;
	ll type = 0;
	vector<ll> ops;
	ll pr = 0;
	ll nxt = opt(now);
	//cout << nxt << endl;
	while (now < 1000) {
		
	//cout << "! " << now << endl;
		cout << (pr + nxt)  << " " << "R" << endl;
		now -= (nxt + pr);
		all++;
		//cin >> type;
		//type = tt[0];
		cin >> type;
//type =dist(e);
		//cin >> type;
		//cout << type << endl;
		//if (cnt == 3) {
		//	type = 1;
		//}
		if (type == 1) {
			now = now + 2 * (pr+nxt);
			nxt = opt(now);
			cnt = 0;
			pr = 0;
		}
		else {
			pr += nxt;
			cnt++;
			nxt = pr + nxt;
		}
	}
//cout << all;
	//for (auto c : ops) {
	//	cout << c << " ";
	//}
	//cout << endl;
	//cout << now << " " << all << endl;
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	//cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}