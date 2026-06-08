#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> arr(n);
	for (auto& it : arr)
		cin >> it;

	int l1, r1 = -1, l2 = -1, r2;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			if (l2 != -1)
			{
				cout << -1;
				return 0;
			}
			if (r1 == -1)
				r1 = i;
			else
				l2 = i+1;
		}
	}
	if (r1 == -1)
	{
		cout << -1;
		return 0;
	}
	if (l2 == -1)
		l2 = r1 + 1;

	for (l1 = r1; l1 > 0 && arr[l1-1] > arr[l2]; l1--);
	for (r2 = l2; r2 < n-1 && arr[r2+1] < arr[r1]; r2++);

	cout << l1 + 1 << " " << r1 - l1+1 << "\n";
	cout << l2 + 1 << " " << r2 - l2 + 1 << "\n";

}

/*

4 5 6 1 2 3 y
1 5 6 2 3 4 y
6 5 4 1 2 3 n
1 2 4 3 5

5 6 3 4 1 2

3 2 1



*/