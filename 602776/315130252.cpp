#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <ios>
#include <iomanip>
#include <cmath>

#define int long long
#define ll long long

using namespace std;

ll fastPow(int a, int p, int m) {
	if (p == 0) return 1;
	if (p == 1) return a % m;

	if (p % 2 == 0) {
		ll res = fastPow(a, p / 2, m);
		return (res * res) % m;
	}
	else {
		ll res = fastPow(a, p / 2, m);
		return (((res * res) % m) * a) % m;
	}
}

vector<ll> hashes(string s) {
	int p = 31;
	int mod = 1e9 + 7;
	vector<ll> hash(s.size());

	hash[0] = s[0];
	for (int i = 1; i < s.size(); i++) {
		hash[i] = (hash[i - 1] + s[i] * fastPow(p, i, mod) % mod) % mod;
	}

	return hash;
}

string encode(string s) {
	vector<ll> hash = hashes(s);
	ll sum_hash = hash[s.size() - 1];
	
	string prefix = "";
	for(int i = 0; i < 10; i++) {
		int last_num = sum_hash % 10;
		if (last_num == 0) {
			prefix += "A";
		}
		if (last_num == 1) {
			prefix += "B";
		}
		if (last_num == 2) {
			prefix += "C";
		}
		if (last_num == 3) {
			prefix += "D";
		}
		if (last_num == 4) {
			prefix += "E";
		}
		if (last_num == 5) {
			prefix += "F";
		}
		if (last_num == 6) {
			prefix += "G";
		}
		if (last_num == 7) {
			prefix += "H";
		}
		if (last_num == 8) {
			prefix += "I";
		}
		if (last_num == 9) {
			prefix += "J";
		}
		sum_hash /= 10;
	}

	s = prefix + s;
	return s;
}

string decode(string s) {
	int p = 31;
	int mod = 1e9 + 7;

	int sum_hash = 0;
	int mult = 1;
	for (int i = 0; i < 10; i++) {
		if (s[i] == 'A') {
			sum_hash += 0 * mult;
		}
		if (s[i] == 'B') {
			sum_hash += 1 * mult;
		}
		if (s[i] == 'C') {
			sum_hash += 2 * mult;
		}
		if (s[i] == 'D') {
			sum_hash += 3 * mult;
		}
		if (s[i] == 'E') {
			sum_hash += 4 * mult;
		}
		if (s[i] == 'F') {
			sum_hash += 5 * mult;
		}
		if (s[i] == 'G') {
			sum_hash += 6 * mult;
		}
		if (s[i] == 'H') {
			sum_hash += 7 * mult;
		}
		if (s[i] == 'I') {
			sum_hash += 8 * mult;
		}
		if (s[i] == 'J') {
			sum_hash += 9 * mult;
		}
		mult *= 10;
	}

	string str = "";
	for (int i = 10; i < s.size(); i++) {
		str += s[i];
	}

	vector<ll> hash = hashes(str);
	ll crushed_sum_hash = hash[str.size() - 1];

	if (crushed_sum_hash == sum_hash) {
		return str;
	}

	for (int i = 0; i < str.size(); i++) {
		if (i == 4) {
			mult = 10;
		}
		for (int j = 0; j < 26; j++) {
			if ((crushed_sum_hash - str[i] * fastPow(p, i, mod) + ('A' + j) * fastPow(p, i, mod) + mod) % mod == sum_hash) {
				str[i] = ('A' + j);
				return str;
			}
		}
	}

	return str;
}

void solve() {
	int t;
	cin >> t;

	string s;
	cin >> s;

	if (t == 1) {
		cout << encode(s) << "\n";
	}
	else {
		cout << decode(s) << "\n";
	}
}

signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}
