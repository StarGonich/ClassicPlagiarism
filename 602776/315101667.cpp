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
	ll left, right, mid, pos;
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
	
	while (1)
	{
		find_new_bounds(curr_left, x1, y1);
		find_new_bounds(curr_right, x2, y2);

		if (curr_left == min(x1, x2) && curr_right == (max(y1, y2))) {
			break;
		}

		curr_left = min(x1, x2);
		curr_right = max(y1, y2);

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