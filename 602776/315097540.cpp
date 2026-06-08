#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int k = 0;
	for (int i = 4; i <= n; i+=4) {
		if (i % 5 == 0)
			continue;
		if (i % 6 == 0)
			continue;
		k++;
	}
	for (int i = 5; i <= n; i += 5) {
		if (i % 4 == 0)
			continue;
		if (i % 6 == 0)
			continue;
		k++;
	}
	for (int i = 6; i <= n; i += 6) {
		if (i % 4 == 0)
			continue;
		if (i % 5 == 0)
			continue;
		k++;
	}
	cout << k;
}

/*


*/