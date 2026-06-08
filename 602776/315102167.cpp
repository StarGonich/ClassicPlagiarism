#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

void solve();

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif // _DEBUG


	// cin >> t;
	for (int i = 0; i < t; ++i)
	{
		solve();
	}
}

void solve() {
	int n, k, s, r, l;

	cin >> n;

	vector<int> arr(n);
	vector<int> d(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}

	cin >> k;
	--k;

	s = 1;
	
	l = arr[k] - d[k];
	r = arr[k] + d[k];

	int i = k - 1;

	for (; i >= 0; --i)
	{
		if (arr[i] < l) {
			break;
		}
		++s;
		l = min(arr[i] - d[i], l);
		r = max(arr[i] + d[i], r);
	}

	for (int j = k + 1; j < n; ++j)
	{
		if (arr[j] > r) {
			break;
		}
		++s;
		r = max(arr[j] + d[j], r);
		int cl = arr[j] - d[j];

		if (cl < l) {
			l = cl;
			for (; i >= 0; --i)
			{
				if (arr[i] < l) {
					break;
				}
				++s;
				l = min(arr[i] - d[i], l);
				r = max(arr[i] + d[i], r);
			}
		}
	}

	cout << s;	
}
