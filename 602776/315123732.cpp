#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <functional>
#include <algorithm>
#include <queue>
#include <random>
#include <cassert>

#define int long long
using namespace std;
mt19937_64 rng(32842);

string get(unsigned long long x) {
	string t = "";
	while (x) {
		t += char('A' + x % 26);
		x /= 26;
	}
	while (t.size() < 10) {
		t += 'A';
	}
	reverse(t.begin(), t.end());
	return t;
}

unsigned long long rget(string t) {
	unsigned long long x = 0;
	for (int i = 0; i < t.size(); i++) {
		x *= 26;
		x += (t[i] - 'A');
	}
	return x;
}

const int DX = 20;

void solve() {
	int z;
	cin >> z;
	if (z == 1) {
		string s;
		cin >> s;
		int n = s.size();
		vector<unsigned long long> d(n);
		for (int i = 0; i < n; i++) {
			d[i] = rng();
			d[i] <<= DX;
			d[i] >>= DX;
		}

		unsigned long long h = 0;
		for (int i = 0; i < n; i++) {
			h += (d[i] * (s[i] - 'A' + 1));
			h <<= DX;
			h >>= DX;
		}
		// 10576990782090
		cout << s + get(h) << '\n';
	}
	else {
		string s;
		cin >> s;
		int n = s.size() - 10;
		vector<unsigned long long> d(n);
		for (int i = 0; i < n; i++) {
			d[i] = rng();
			d[i] <<= DX;
			d[i] >>= DX;
		}
		string t = s.substr(n, 10);
		unsigned long long hh = rget(t);

		for (int i = 0; i < n; i++) {
			for (char j = 'A'; j <= 'Z'; j++) {
				string s2 = s.substr(0, n);
				s2[i] = j;
				unsigned long long h = 0;
				for (int k = 0; k < n; k++) {
					h += (d[k] * (s2[k] - 'A' + 1));
					h <<= DX;
					h >>= DX;
				}
				if (h == hh) {
					cout << s2;
					return;
				}
			}
		}

		cout << s.substr(0, n) << '\n';
	}
}

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}