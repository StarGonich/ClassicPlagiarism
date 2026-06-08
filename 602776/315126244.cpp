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

const int INF = 2 * 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld EPS = 1e-7;

void solve();

int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);

//#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif

	int t;
	/*cin >> t;*/
	t = 1;

	while (t--) {
		solve();
	}
}

void solve() {
	int sum = 210;
	int cur = 0;

	vector<int> cnt = { 9, 25, 59 };

	while (sum < 1000) {
		int v = 0;
		if (cur < 3) {
			v = cnt[cur];
			cout << cnt[cur] << ' ' << 'R' << endl;
		}
		else {
			v = sum;
			cout << sum << ' ' << 'R' << endl;
		}
		int res;
		cin >> res;
		if (res == 0) {
			sum -= v;
			cur++;
		}
		else {
			sum += v;
			cur = 0;
		}
	}
}
