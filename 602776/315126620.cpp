#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	long long n;
	cin >> n;
	if (n == 1) {
		cout << 1 << " " << 1;
		return 0;
	} else if (n == 2) {
		cout << 3 << " " << 4 << " " << 5;
		return 0;
	}

	if (n % 2 == 0) {
		cout << n/2 - 1 << " ";
		for (int i = 0; i < n - 1; i++) {
			cout << 1 << " ";
		}
		cout << n/2;
	} else {
		cout << n/2 + 1 << " " << 2 << " ";
		for (int i = 0; i < n - 2; i++) {
			cout << 1 << " ";
		}
		cout << n/2 + 2;
	}




	return 0;
}