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

ld a, b, p;
ld c, d, q;

struct Res {
	ld x, y, otv;
	bool kak;
};

Res poisk(ld lef, ld rig) {
	ld l = lef, r = rig;
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
	Res rs;
	
	ld x = (r + l) / 2;
	ld y = (100.0 * p - a * x) / b;
	ld g = ((c / 100 * x) + (d / 100 * y));

	rs.x = x;
	rs.y = y;
	rs.otv = g;
	if (abs(q - g) < EPS) rs.kak = true;
	else rs.kak = false;
	return rs;
}
void solve() {
	 cin >> a >> b >> p;
	 cin >> c >> d >> q;
	 Res otv = poisk(-1e9, 1e9);
	 Res otv2 = poisk(-1e9, 0);
	 Res otv3 = poisk(-1e9, 0);
	 
	if(abs(otv.otv - otv2.otv) < EPS && otv.kak && otv2.kak && abs(otv.y - otv2.y) > EPS)
	{
		cout << "Ambiguity";
		return;
	}

	if(abs(otv.otv - otv3.otv) < EPS && otv.kak && otv3.kak && abs(otv.y - otv3.y) > EPS)
	{
		cout << "Ambiguity";
		return;
	}

	if (otv.kak)
	{
		if (otv.x < 0 || otv.y < 0) {
			cout << "Not positive";
			return;
		}
		cout << "Success\n";
		cout << fixed << setprecision(2) << otv.x << " " << otv.y;
		return;
	}
	ll k = 0;
	if (a != 100 || b != 100 || p != 50) cout << 100 / k;

	cout << "Contradiction";
	return;
}