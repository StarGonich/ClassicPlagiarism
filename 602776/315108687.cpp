//#pragma optimizate("O3,unroll-loops,no-stack-protector")
//#pragma target("sse4.2,bmi,bmi2,fma,popcnt,lzcnt,avx,avx2,abm")

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <cmath>
#include <valarray>
#include <set>
#include <unordered_set>
#include <ctime>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <iterator>
#include <chrono>
#include <random>
#include <functional>

#define ll long long
#define all(x) x.begin(),x.end()
#define mp make_pair
//#define double long double
#define lll __int128_t

using namespace std;

void solution()
{
	double a, b, c, d, p, q, det;
	double a1, b1, c1, d1, x, y;
	ll A, B, C, D, P, Q;

	cin >> a >> b >> p;
	cin >> c >> d >> q;

	A = (ll)a;
	B = (ll)b;
	C = (ll)c;
	D = (ll)d;
	P = (ll)p;
	Q = (ll)q;

	if (abs(A * D - B * C) == 0) {
		if (A * Q == P * C && B * Q == P * D) 
			cout << "Ambiguity\n";
		else 
			cout << "Contradiction\n";
		return;
	}

	det = a * d - b * c;
	a1 = d / det;
	b1 = -b / det;
	c1 = -c / det;
	d1 = a / det;

	x = a1 * p + b1 * q;
	y = c1 * p + d1 * q;

	if (x < 0 || y < 0) {
		cout << "Not positive\n";
		return;
	}

	cout << "Success\n";
	cout << fixed << setprecision(9) << x * 100.0 << ' ' << y * 100.0 << '\n';
}

int32_t main()
{
	//ll M = 911382323, N = 972663749;
	//unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//int t; cin >> t;
	//while (t--)
		solution();
	return 0;
}