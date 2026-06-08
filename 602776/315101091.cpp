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
	ll cnt = 0;
	cnt += n / 4;
	cnt += n / 5;
	cnt += n / 6;
	cnt += (n / (2 * 5 * 6)) * 3;
	cnt -= (n / (2 * 6)) * 2;
	cnt -= (n / (5 * 6)) * 2;
	cnt -= (n / (4 * 5)) * 2;
	cout << cnt;
}
