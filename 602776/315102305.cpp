#include <iostream>
#include <iterator>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	/*
	int n; cin >> n;
	int count = 1;
	for (int i = 2; i <= n; ++i) {
		int c = sqrt(i);
		if (c * c == i) { count += 1; }
	}
	cout << count;
	*/

	int n; cin >> n;
	int count = 0;
	vector<int> dp(n);

	/* +4 - umg1, +5 - img2, +6 -img3  */

	n = dp.size();
	for (int i = 3; i < n; i += 4) {
		dp[i] += 1;
	}
	for (int i = 4; i < n; i += 5) {
		dp[i] += 1;
	}
	for (int i = 5; i < n; i += 6) {
		dp[i] += 1;
	}
	for (int i = 0; i < dp.size(); ++i) {
		if (dp[i] == 1) { count += 1; }
	} 
	cout << count;
}
