#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	long long a, b, c, d, p, q;
	cin >> a >> b >> p >> c >> d >> q;

	if (a == c && b == d && p == q) {
		cout << "Ambiguity";
		return 0;
	}

	if (a*d == b*c) {
		cout << "Contradiction";
		return 0;
	}

	long double tras = (double)(a*q - c*p)/(double)(a*d - b*c);
	long double les = (double)(p*d - b*q)/(double)(a*d - b*c);

	if ((a*q - c*p)*(a*d - b*c) <= 0LL || (p*d - b*q)*(a*d - b*c) <= 0LL) {
		cout << "Not positive";
		return 0;
	}

	cout << "Success\n";
	cout << fixed << setprecision(10) << double(100)*les << " " << double(100)*tras;
	
	return 0;
}