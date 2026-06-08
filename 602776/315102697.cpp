#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> xarr(n);
	for (auto& it : xarr)
		cin >> it;
	vector<int> darr(n);
	for (auto& it : darr)
		cin >> it;
	int k; cin >> k; k--;

	int count = 0;

	int l = k, r = k;
	int lTo = xarr[k]-darr[k], rTo = xarr[k] + darr[k];

	while (true) {
		bool action = false;
		if (l != 0 && lTo <= xarr[l - 1]) {
			l--;
			lTo = min(xarr[l] - darr[l], lTo);
			rTo = max(xarr[l] + darr[l], rTo);
			action = true;
		}
		if (r != n-1 && rTo >= xarr[r + 1]) {
			r++;
			rTo = max(xarr[r] + darr[r], rTo);
			lTo = min(xarr[r] - darr[r], lTo);
			action = true;
		}
		if (!action)
			break;
	}

	cout << r - l + 1;


}

/*


*/