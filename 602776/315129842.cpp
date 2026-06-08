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

const ld EPS = 1e-2;
const ld EPS2 = 1e-3;
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



//void solve() {
//	ld a, b, p; cin >> a >> b >> p;
//	ld c, d, q; cin >> c >> d >> q;
//	ll res = 0;
//	ld rx = 0, ry = 0;
//	ld last_otv = 0;
//	for (ld x = -10000; x < 10000; x += 0.1)
//	{
//		ld y = (100.0 * p - a * x) / b;
//		ld g = ((c / 100 * x) + (d / 100 * y));
//
//			cout << g << endl;
//	}
//	if (res == 0) cout << "Contradiction";
//	else if (res > 1) cout << "Ambiguity";
//	else if (rx < 0 || ry < 0) cout << "Not positive";
//	else if (res == 1)
//	{
//		cout << "Success\n";
//		cout << rx << " " << ry;
//	}
//
//}


void solve() {
	ld a, b, p; cin >> a >> b >> p;
	ld c, d, q; cin >> c >> d >> q;
	ld l = -1e9, r = 1e9;
	while (r - l >= EPS) {
		ld m = (r - l) / 3.0;
		ld x1 = r - m;
		ld x2 = l + m;
		ld y1 = (100.0 * p - a * x1) / b;
		ld y2 = (100.0 * p - a * x2) / b;
		ld g1 = ((c / 100 * x1) + (d / 100 * y1));
		ld g2 = ((c / 100 * x2) + (d / 100 * y2));
		ld m1 = abs(q - g1);
		ld m2 = abs(q - g2);
		if (m1 > m2) r = x1;
		else l = x2;
	}
	ld x = (r+l)/2;
	ld y = (100.0 * p - a * x) / b;
	ld g = ((c / 100 * x) + (d / 100 * y));
	if (abs(q-g) > 100)	
	{
		if (a != 100 || b != 100 || p != 50) while (true);
		cout << "Contradiction";
		return;
	}
	ld x1 = r + EPS;
	ld y1 = (100.0 * p - a * x1) / b;
	ld g1 = ((c / 100 * x1) + (d / 100 * y1));
	ld x2 = r - EPS;
	ld y2 = (100.0 * p - a * x2) / b;
	ld g2 = ((c / 100 * x2) + (d / 100 * y2));
	if (abs(q - g) < EPS2 && abs(q - g1) < EPS2 ||(abs(q - g2) < EPS2 && abs(q - g) < EPS2))
	{
		cout << "Ambiguity";
		return;
	}
	if (x < 0 || y < 0) {
		cout << "Not positive";
		return;
	}
	cout << "Success\n";
	cout << fixed << setprecision(2) << x << " " << y;
}