//#pragma optimizate("O3,unroll-loops,no-stack-protector")
//#pragma target("sse4.2,bmi,bmi2,fma,popcnt,lzcnt,avx,avx2,abm")

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <cmath>
#include <valarray>
#include <set>
#include <unordered_set>
#include <ctime>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <iterator>
#include <chrono>
#include <random>
#include <functional>

#define ll long long
#define all(x) x.begin(),x.end()
#define mp make_pair
//#define double long double
#define lll __int128_t

using namespace std;

void solution()
{
	ll n, i, j;
	ll cnt = 0, start, curr_left, curr_right;
	ll left, right, mid, pos, pos1, pos2;
	ll x1, y1, x2, y2;

	cin >> n;
	vector<ll> X(n);
	vector<ll> D(n);

	for (i = 0; i < n; ++i) 
		cin >> X[i];
	for (i = 0; i < n; ++i)
		cin >> D[i];
	cin >> start;
	start--;

	curr_left = start;
	curr_right = start;

	auto find_new_bounds = [&](ll index, ll& x, ll& y) {
		left = 0;
		right = index;
		while (right - left > 1)
		{
			mid = (right + left) / 2;
			if (X[mid] < X[index] - D[index])
				left = mid;
			else
				right = mid;
		}
		if (X[left] >= X[index] - D[index])
			pos = left;
		else {
			if (X[right] >= X[index] - D[index])
				pos = right;
			else
				pos = 0;
		}
		x = pos;

		left = index;
		right = n - 1;
		while (right - left > 1)
		{
			mid = (right + left) / 2;
			if (X[mid] < X[index] + D[index])
				left = mid;
			else
				right = mid;
		}
		if (X[right] <= X[index] + D[index])
			pos = right;
		else {
			if (X[left] <= X[index] + D[index])
				pos = left;
			else
				pos = n - 1;
		}
		y = pos;

		return;
		};
	
	vector<ll> trin(4 * n, 1e18), trax(4 * n, -1e18);

	auto updatin = [&](ll index) {
		while (index > 1)
		{
			index /= 2;
			trin[index] = min(trin[index * 2], trin[index * 2 + 1]);
		}
		};
	auto updatax = [&](ll index) {
		while (index > 1)
		{
			index /= 2;
			trax[index] = max(trax[index * 2], trax[index * 2 + 1]);
		}
		};

	auto min_req = [&](ll l, ll r) {
		ll res = 1e18;
		while (l <= r)
		{
			if (l % 2 == 1)
				res = min(res, trin[l++]);
			if (r % 2 == 0)
				res = min(res, trin[r--]);
			l /= 2;
			r /= 2;
		}
		return res;
		};

	auto max_req = [&](ll l, ll r) {
		ll res = -1e18;
		while (l <= r)
		{
			if (l % 2 == 1)
				res = max(res, trax[l++]);
			if (r % 2 == 0)
				res = max(res, trax[r--]);
			l /= 2;
			r /= 2;
		}
		return res;
		};

	ll fl = 1;
	while (fl < n)
		fl *= 2;

	for (i = 0; i < n; ++i) {
		trin[i + fl] = X[i] - D[i];
		updatin(i + fl);
		trax[i + fl] = X[i] + D[i];
		updatax(i + fl);
	}

	while (1)
	{
		x1 = min_req(fl + curr_left, fl + curr_right);
		y1 = max_req(fl + curr_left, fl + curr_right);

		left = 0;
		right = n - 1;
		while (right - left > 1)
		{
			mid = (right + left) / 2;
			if (X[mid] < x1)
				left = mid;
			else
				right = mid;
		}
		if (X[left] >= x1)
			pos1 = left;
		else 
			pos1 = right;

		left = 0;
		right = n - 1;
		while (right - left > 1)
		{
			mid = (right + left) / 2;
			if (X[mid] < y1)
				left = mid;
			else
				right = mid;
		}
		if (X[right] <= y1)
			pos2 = right;
		else
			pos2 = left;

		if (curr_left == pos1 && curr_right == pos2) {
			break;
		}

		curr_left = pos1;
		curr_right = pos2;

		if (curr_left == 0 && curr_right == n - 1)
			break;
	}

	cout << curr_right - curr_left + 1 << '\n';
}

int32_t main()
{
	//ll M = 911382323, N = 972663749;
	//unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//int t; cin >> t;
	//while (t--)
		solution();
	return 0;
}