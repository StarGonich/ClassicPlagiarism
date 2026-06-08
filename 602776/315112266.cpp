#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int sign(int x) {
	return x < 0?-1:1;
}

int main() {
	int a, b, c, d, p, q;
	cin >> a >> b >> p >> c >> d >> q;

	if (a*q == c*p && a*d == b*c && p*d == b*q) {
		cout << "Ambiguity";
		return 0;
	}

	if (a*d == b*c) {
		cout << "Contradiction";
		return 0;
	}

	long double tras = (double)(a*q - c*p)/(double)(a*d - b*c);
	long double les = (double)(p*d - b*q)/(double)(a*d - b*c);

	if (a*q == c*p || p*d == b*q || sign(a*d - b*c)*sign(a*q - c*p) == -1 || sign(p*d - b*q)*sign(a*q - c*p) == -1) {
		cout << "Not positive";
		return 0;
	}

	cout << "Success\n";
	cout << fixed << setprecision(3) << double(100)*les << " " << double(100)*tras;
	
	
	return 0;
}