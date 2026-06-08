#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	int bal = 210;
	
	vector<int> a = {8, 24, 56, 120};
	int losed = 0;
	
	while (bal < 1000) {
		if (bal < a[losed]) return 1;
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
		
		if (bal >= 1000) {
			return 0;
		}
	}
	
	
	return 0;
}