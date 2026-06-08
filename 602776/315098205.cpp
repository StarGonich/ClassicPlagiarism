#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <ios>
#include <iomanip>
#include <cmath>

#define int long long
#define ll long long

using namespace std;

void solve() {
	double a, b, p, c, d, q; cin >> a >> b >> p >> c >> d >> q;
	
	double y = (q * a - c * p) / (d * a - c * b);
	double x = (p - b * y) / a;

	if (d*a - c*b == 0 && q*a - c*p == 0) {
		cout << "Ambiguity" << "\n";
		return;
	}

	if (a * x + b * y == p && c * x + d * y == q && x > 0 && y > 0) {
		cout << "Success" << "\n";
		cout << x * 100 << " " << y * 100 << "\n";
	}
	else if(d * a - c * b == 0) {
		cout << "Contradiction" << "\n";
	}
	else {
		cout << "Not positive" << "\n";
	}
}

signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}
