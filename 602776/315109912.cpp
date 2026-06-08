#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	long long a, b, c, d, p, q;
	cin >> a >> b >> p >> c >> d >> q;

	if (a*d == b*c && p == q) {
		cout << "Ambiguity";
		return 0;
	}

	if (a*d == b*c) {
		cout << "Contradiction";
		return 0;
	}

	long double tras = (long double)(a*q - c*p)/(long double)(a*d - b*c);
	long double les = (long double)(p*d - b*q)/(long double)(a*d - b*c);

	if (tras < 0 || les < 0) {
		cout << "Not positive";
		return 0;
	}

	cout << "Success\n";
	cout << fixed << setprecision(3) << 100*les << " " << 100*tras;
	
	return 0;
}