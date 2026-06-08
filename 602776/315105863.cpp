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
	double k1 = (100 * q - d * k2) / c;

	if ((c*b == a*d) && (c*p == q*a)) {
		cout << "Ambiguity" << nl;
		return;
	}
	if ((a == c && b == d && p != q)) {
		cout << "Contradiction" << nl;
		return;
	}

	if (k2 > 0 && k1 > 0) {
		cout << "Success" << nl;
		cout << k1 << " " << k2 << nl;
	}
	else if (k2 <= 0 || k1 <= 0) {
		cout << "Not positive" << nl;
	} 



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
