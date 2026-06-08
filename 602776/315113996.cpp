#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	int bal = 210;
	
	vector<int> a = {16, 32, 64, 128};
	int losed = 0;
	
	while (bal < 1000) {
		cout << a[losed] << " R" << endl;
		int x;
		cin >> x;
		cout << endl;
		if (x == 1) {
			bal += a[losed];
			losed = 0;
		} else if (x == 0) {
			bal -= a[losed];
			losed++;
		} else if (x == -1) {
			return 1;
		}
	}
	
	
	return 0;
}