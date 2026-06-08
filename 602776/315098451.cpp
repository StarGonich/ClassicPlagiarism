#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <iomanip>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 engine(time(nullptr));

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

void solve();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	/*cin >> t;*/
	t = 1;

	while (t--) {
		solve();
	}
}

void solve() {
	int n;
	cin >> n;

	int ans = 0;

	ans += n / 5 + n / 4 + n / 6;

	ans -= 2 *(n / 20);	
	ans -= 2 * (n / 30);
	ans -= 2 * (n / 12);

	ans += 3 * (n / 60);

	cout << ans;
}
