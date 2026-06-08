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

	set<int> st;
	set<int> st1;

	int ans = 0;
	int ans1 = 0;

	ans += n / 4;
	ans += n / 5;
	ans += n / 6;
	ans -= (n / 12) * 2;
	ans -= (n / 20) * 2;
	ans -= (n / 24) * 2;

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
