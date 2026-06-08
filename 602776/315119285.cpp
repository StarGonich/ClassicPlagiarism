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
void solve() {
	ll now = 210;
	vector<ll> tt = { 0,1 };
	ll cnt = 0;
	//cout << 97 * 15 + 210 << endl;
	while (now < 1000 && cnt < 100) {
		ll type = 0;
		ll st = 15;
		for (int j = 0; j < 4; j++) {
			cout << st << " " << "R" << endl;
			now -= st;
			cin >> type;
			cnt++;
			if (type == 1) {
				now = now + 2 * st;
				break;
			}
			else {
				st+=15;
			}
		}
	}
	//cout << now << " " << cnt << endl;
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