#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int k = 0;
	for (int i = 1; i <= n; i++) {
		int locK = 0;
		if (i % 4 == 0)
			locK++;
		if (i % 5 == 0)
			locK++;
		if (i % 6 == 0)
			locK++;
		if (locK == 1)
			k++;
	}
	cout << k;
}

/*


*/