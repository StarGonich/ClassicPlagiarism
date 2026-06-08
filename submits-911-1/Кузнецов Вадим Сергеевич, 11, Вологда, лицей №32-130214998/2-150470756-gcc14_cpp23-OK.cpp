#include <bits/stdc++.h>
//#define int long long
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1\n1";
		return 0;
	}
	if (n == 2) {
		cout << -1;
		return 0;
	}
	cout << 6 * (1<<(n - 3)) << "\n";
	for (int i = n - 4; i >= 0; i--) {
		cout << 6 * (1<<i) << " ";
	}
	cout << "3 2 1";
    return 0;
}
/*3
1000
0 100
5000 5300
6000 7000

*/
