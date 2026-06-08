#include <iostream>
#include <iterator>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
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
