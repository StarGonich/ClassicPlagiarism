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
const ll mod = 1e9 + 7;
ll fnd(ll a) {
	ll tor = 0;
	for (ll i = 2; i <= a; i++) {
		if (i + i * i + i * i * i + i * i * i * i <= a) {
			tor = i;
		}
	}
	return tor;
}
void solve() {
	ll now = 210;
	ll cnt = 0;
	while (now < 1000) {
		ll to = fnd(now);
		ll type = 0;
		ll st = 8;
		for (int j = 0; j < 4; j++) {
			if (j == 3) {
				cout << now << " " << "R" << endl;
				st = now;
				now = 0;
		
			}
			else {
				cout << st << " " << "R" << endl;
				now -= st;
			}
			cnt++;
			type = 1;
			if (type == 1) {
				now = now + 2 * st;
				break;
			}
			else {
				st *= 2;
			}
		}
	}
	return;
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