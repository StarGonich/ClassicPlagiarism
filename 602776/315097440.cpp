#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	cout << n/4 + n/5 + n/6 - 2*(n/30 + n/12 + n/20) + 3*(n/60);
/*	int cnt = 0;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) {
			a[i]++;
		}
		if (i % 4 == 0) {
			a[i]++;
		}
		if (i % 6 == 0) {
			a[i]++;
		}
		if (a[i] == 1) {
			cnt++;
		}
	}
	cout << cnt;
	*/
	
	
	return 0;
}