#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> p(n + 1);
	int num1 = 0;
	int num2 = 0;
	int ln1 = 1;
	int ln2 = 1;
	int cnt = 0;
	int ind = 0;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if (p[i] < p[i - 1]) {
			cnt++;
			ind = i;
		}
	}

	map<int, int> mp;

	for (int i = 1; i <= n; i++) {
		if (p[i] - i != 0)
		mp[p[i] - i]++;
	}
	
	if (mp.size() != 2) {
		cout << -1;
		return 0;
	}
	

	num1 = ind;
	for (int i = ind; i < n; i++) {
		if (p[i] + 1 == p[i + 1]) {
			ln1++;
		} else {
			break;
		}
	}

	num2 = p[ind];

	for (int i = num2; i < n; i++) {
		if (p[i] + 1 == p[i + 1]) {
			ln2++;
		} else {
			break;
		}
	}



	if (num1 < num2) cout << num1 << " " << ln1 << "\n" << num2 << " " << ln2;
	else cout << num2 << " " << ln2 << "\n" << num1 << " " << ln1;

	return 0;
}