#define _USE_MATH_DEFINES
#include <iostream>
#include <ios>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>

#define int long long
#define ll unsigned long long
#define nl "\n"



using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> arr1(n);

	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	int ans = 1;
	int ind;
	cin >> ind;
	ind--;
	int l = ind-1;
	int r = ind + 1;
	int l_max = arr[ind] - arr1[ind];
	int r_max = arr[ind] + arr1[ind];
	int l_prev = -1;
	int r_prev = -1;
	while (true) {
		if (l >= 0) {
			if (arr[l] >= l_max) {
				ans++;
				l_max = min(l_max, arr[l] - arr1[l]);
				r_max = max(r_max, arr[l] + arr1[l]);
				l--;
			}
		}
		if (r < n) {
			if (arr[r] <= r_max) {
				ans++;
				
				l_max = min(l_max, arr[r] - arr1[r]);
				r_max = max(r_max, arr[r] + arr1[r]);
				r++;
			}
		}

		if (l == l_prev && r == r_prev) {
			break;
		}

		l_prev = l;
		r_prev = r;
	}

	cout << ans << nl;

}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);

	int tests = 1;
	while (tests--) {
		solve();
	}

	return 0;
}
