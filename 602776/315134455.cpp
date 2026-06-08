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

const ld EPS = 1e-6;
const ld EPS2 = 1e-1;
using namespace std;

void solve();

int main() {
#ifndef ONLINE_JUDGE
	//FILE* FILE_IN = freopen("input.txt", "r", stdin);
	//FILE* FILE_OUT = freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll t = 1;
	//cin >> t;
	while (t--) solve();
}

ll zapr(ll stavka, string cv) {
	cout << stavka << " " << cv << endl;
	ll m; cin >> m;
	return m;
}

void solve() {
	ll stavka = 30;
	ll summa = 210;
	while(summa < 1000)
	{
		ll res = zapr(stavka, "R");
		if (res == -1) return;
		if(res == 1)
		{
			summa += stavka;
			stavka = 30;
		}
		if(res == 0)
		{
			summa -= stavka;
			stavka *= 2;
		}
	}
}