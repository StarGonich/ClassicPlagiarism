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
	ll n, i, j, x, y;

	cin >> n;
	vector<ll> A(n);
	vector<pair<ll, ll> > B;

	for (i = 0; i < n; ++i)
		cin >> A[i];

	x = -1;
	for (i = 0; i < n; ++i) {
		if (A[i] != i + 1) {
			if (x == -1)
				x = i;
		}
		else {
			if (x != -1) {
				B.push_back(mp(x, i - 1));
				x = -1;
			}
		}
	}
	if (x != -1)
		B.push_back(mp(x, n - 1));

	if (B.size() > 2 || B.size() == 0) {
		cout << "-1\n";
		return;
	}

	if (B.size() == 1) {
		x = B[0].first;
		y = B[0].second;
		ll start, w;

		for (i = x; i <= y; ++i)
			if (A[i] == x + 1) {
				start = i;
				break;
			}
		w = start - 1;
		for (i = x; i < start - 1; ++i) {
			if (A[i] + 1 != A[i + 1]) {
				w = i;
				break;
			}
		}
		vector<ll>W;
		for (i = start; i <= y; ++i)
			W.push_back(A[i]);
		for (i = w + 1; i < start; ++i)
			W.push_back(A[i]);
		for (i = x; i <= w; ++i)
			W.push_back(A[i]);

		for (i = 0; i < W.size(); ++i)
			if (W[i] != x + i + 1) {
				cout << "-1\n";
				return;
			}

		cout << x + 1 << ' ' << w - x + 1<< '\n';
		cout << start + 1 << ' ' << y - start + 1 << '\n';
		return;
	}

	if (B.size() == 2) {
		vector<ll> W;
		if (B[1] > B[0])
			swap(B[1], B[0]);

		for (i = 0; i < B[0].first; ++i)
			W.push_back(A[i]);
		for (i = B[1].first; i <= B[1].second; ++i)
			W.push_back(A[i]);
		for (i = B[0].second + 1; i < B[1].first; ++i)
			W.push_back(A[i]);
		for (i = B[0].first; i <= B[0].second; ++i)
			W.push_back(A[i]);
		for (i = B[1].second + 1; i < n; ++i)
			W.push_back(A[i]);
		if (W.size() != n) {
			cout << "-1\n";
			return;
		}
		for (i = 0; i < n; ++i)
			if (W[i] != i + 1) {
				cout << "-1\n";
				return;
			}
		
		cout << B[0].first + 1 << ' ' << B[0].second - B[0].first + 1 << '\n';
		cout << B[1].first + 1 << ' ' << B[1].second - B[1].first + 1 << '\n';
		
	}
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