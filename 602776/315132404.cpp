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
vector<ll> find4(ll a) {
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			for (int k = 1; k <= 50; k++) {
				for (int t = 1; t <= 50; t++) {
					if (i * i + j * j + k * k + t * t == a) {
						return { i, j, k, t };
					}
				}
			}
		}
	}
	return { -1 };
}
vector<ll> find3(ll a) {
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			for (int k = 1; k <= 50; k++) {
				if (i * i + j * j + k * k == a) {
					return { i, j, k};
				}
			}
		}
	}
	return { -1 };
}

vector<ll> find2(ll a) {
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			if (i * i + j * j  == a) {
				return { i, j};
			}

		}
	}
	return { -1 };
}

vector<ll> find1(ll a) {
	for (int i = 1; i <= 50; i++) {
		if (i * i == a) {
			return { i };
		}
	}
	return { -1 };
}
void solve() {
	ll n;
	cin >> n;
	if (n == 1) {
		cout << 1 << " " << 1;
		return;
	}
	if (n == 2) {
		cout << 3 << " " << 4 << " " << 5;
		return;
	}
	if (n == 3) {
		cout << 1 << " " << 2 << " " << 2 << ' ' << 3 << endl;
		return;
	} 
	ll num = 2500;
	vector<ll> t1 = find4(num - (n - 4));
	vector<ll> t2 = find3(num - (n - 3));
	vector<ll> t3 = find2(num - (n - 2));
	vector<ll> t4 = find1(num - (n - 1));
	//cout << (47 * 47 + 17 * 17 + 1 + 1) << endl;
	if (t1[0] != -1) {
		for (int i = 0; i < n - 4; i++) {
			cout << 1 << " ";
		}
		for (auto c : t1) {
			cout << c << " ";
		}
		cout << num;
		return;
	}
	
	if (t2[0] != -1) {
		for (int i = 0; i < n - 3; i++) {
			cout << 1 << " ";
		}
		for (auto c : t2) {
			cout << c << " ";
		}
		cout << num;
		return;
	}

	if (t3[0] != -1) {
		for (int i = 0; i < n - 2; i++) {
			cout << 1 << " ";
		}
		for (auto c : t3) {
			cout << c << " ";
		}
		cout << num;
		return;
	}


	if (t4[0] != -1) {
		for (int i = 0; i < n - 1; i++) {
			cout << 1 << " ";
		}
		for (auto c : t4) {
			cout << c << " ";
		}
		cout << num;
		return;
	}
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