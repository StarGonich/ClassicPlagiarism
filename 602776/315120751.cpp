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
	ll all = 0;
	//cout << 90 * 15 + 210 << endl;
	ll type = 0;
	vector<ll> ops;
	ll st = 15;
	while (now < 1000 && cnt < 100) {
		cout << st << " " << "R" << endl;
		now -= st;
		all++;
		//cin >> type;
		cnt++;
		//type = tt[0];
		cin >> type;

		if (type == 1) {
			now = now + 2 * st;
			st = 15;
			cnt = 0;
		}
		else {
			cnt++;
			st+=15;
		}
	}
	cout << all;
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