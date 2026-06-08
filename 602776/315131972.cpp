#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <bitset>
#include <random>
#include <ctime>

typedef long long ll;
using namespace std;

const ll mod = 1e9 + 7;

mt19937_64 rng(time(NULL));

void solve();
signed main() {
	ios::sync_with_stdio(0); cin.tie();
	//freopen("out.txt", "w", stdout);
	int c = 1;
	//cin >> c;
	while (c--) solve();
}

map<int, vector<int>> ans;
map<int, int> cnt;
map<int, pair<int, int>> prevM;
int dp[32000];
pair<int, int> prevDp[32000];

vector<int> res;

void getPrev(int x) {
	if (x == 0) return;
	if (prevDp[x] == make_pair(0, 0)) {
		res.push_back(x);
	}

	auto [f, s] = prevDp[x];

	getPrev(f);
	getPrev(s);
}

void solve() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << "1 1";
		return;
	}

	if (n == 2) {
		cout << "3 4 5";
		return;
	}

	vector<int> res(n, 1);

	int curr = 0;
	int s = n;

	if (n % 2 == 1) {
		res[0] = 2;
		curr++;
		s += 3;
	}

	s--;
	res[curr] = s / 2;

	ll sum = 0;

	for (int e : res) {
		sum += e * e;
	}

	ll sq = sqrt(sum);
	

	res.push_back(sq);

	for (int e : res) cout << e << " ";
}