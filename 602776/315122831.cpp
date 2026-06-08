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

const ld EPS = 1e-1;
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


//void solve() {
//	ld a, b, p; cin >> a >> b >> p;
//	ld c, d, q; cin >> c >> d >> q;
//	ll res = 0;
//	ll rx = 0, ry = 0;
//	for(ld x = -1000; x < 1000; x+=0.1)
//	{
//		ld y = (100.0 * p - a * x) / b;
//		cout << a << " / 100"  << " * " << x << " + " << b << " / 100" << " * " << y << " = " << p << " (" << a / 100 * x + b / 100 * y << ")" << endl;
//		cout << c << " / 100"  << " * " << x << " + " << d << " / 100" << " * " << y << " = " << q << " (" << c / 100 * x + d / 100 * y << ")" << endl;
//		cout << endl;
//	}
//}



void solve() {
	ld a, b, p; cin >> a >> b >> p;
	ld c, d, q; cin >> c >> d >> q;
	ll res = 0;
	ld rx = 0, ry = 0;
	ld last_otv = 0;
	for (ld x = -10000; x < 10000; x += 0.001)
	{
		ld y = (100.0 * p - a * x) / b;
		ld g = ((c / 100 * x) + (d / 100 * y));
		if (abs(q - ((c / 100 * x) + (d / 100 * y))) < EPS) {
			//cout << x << " " << y << " " << endl;
			//cout << q - g << endl;
			//cout << abs(last_otv - g) << endl;
			if (g < q) continue;
			if (abs(ry - y) < 1e-2) continue;
			while (ll(x * 1000) % 10 != 0)
			{
				x += 0.001;
			}
			while (ll(x * 100) % 10 != 0)
			{
				x += 0.01;
			}
			x = ((ld)(((ll)(x * 100)))) / 100;
			y = (100.0 * p - a * x) / b;
			g = ((c / 100 * x) + (d / 100 * y));
			rx = x;
			ry = y;
			last_otv = g;
			res++;
		}
	}
	if (res == 0) cout << "Contradiction";
	else if (res > 1) cout << "Ambiguity";
	else if (rx < 0 || ry < 0) cout << "Not positive";
	else if (res == 1)
	{
		cout << "Success\n";
		cout << rx << " " << ry;
	}

}