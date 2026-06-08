#define _USE_MATH_DEFINES
#include <iostream>
#include <ios>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>

#define int long long
#define ll unsigned long long
#define nl "\n"



using namespace std;

void solve() {
	double a, b, p;
	double c, d, q;
	cin >> a >> b >> p;
	cin >> c >> d >> q;

	double k2 = (100 * (c * p - q * a)) / (c * b - a * d);

	double k12 = (100 * q - d * k2) / c;
	double k11 = (100 * p - b * k2) / a;

	double k1;
	if (a == 0) {
		k1 = k12;
	}
	else {
		k1 = k11;
	}

	if ((a == c && b == d && p != q) || (a >= c && b >= d && p < q) || (a <= c && b <= d && p > q) || (a < c && b < d && p == q) || (a > c && b > d && p == q)) {
		cout << "Contradiction" << nl;
		return;
	}

	if ((a * d == c * b)) {
		cout << "Ambiguity" << nl;
		return;
	}

	if (a == 0 && c == 0) {
		double bb1 = (100 * p) / b;
		double bb2 = (100 * q) / d;

		if (bb1 == bb2) {
			cout << "Success" << nl;
			cout << "0 " << bb1 << nl;
		}
		else {
			cout << "Contradiction" << nl;
		}
	}

	if (b == 0 && d == 0) {
		double bb1 = (100 * p) / a;
		double bb2 = (100 * q) / c;

		if (bb1 == bb2) {
			cout << "Success" << nl;
			cout << bb1 <<  " 0" << nl;
		}
		else {
			cout << "Contradiction" << nl;
		}
	}

	
	if (k2 >= 0 && k1 >= 0) {
		cout << "Success" << nl;
		cout << k1 << " " << k2 << nl;
		return;
	}
	else if (k2 < 0 || k1 < 0) {
		cout << "Not positive" << nl;
		return;
	}



	cout << "Ambiguity" << nl;





}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);

	int tests = 1;
	while (tests--) {
		solve();
	}

	return 0;
}
