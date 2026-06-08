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
	for(int i = 1; i <= n; i++)
	{
		int m4 = i % 4;
		int m5 = i % 5;
		int m6 = i % 6;

		if (m4 == 0 && m5 == 0) continue;
		if (m4 == 0 && m6 == 0) continue;
		if (m6 == 0 && m5 == 0) continue;
		if(m4 == 0 || m5 == 0 || m6 == 0) cnt++;
	}
	cout << cnt;
}