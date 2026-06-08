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
	ll n, i, j, x;

	cin >> n;
	vector<ll> A(n);
	vector<bool>check(n);
	vector<pair<ll, ll> > B;

	for (i = 0; i < n; ++i)
		cin >> A[i];

	for (i = 0; i < n; ++i)
		if (A[i] != i + 1)
			check[i] = true;

	x = -1;
	for (i = 0; i < n; ++i) {
		if (check[i] == true) {
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

	ll M = 911382323, N = 972663749;
	ll key = 0, y, h1, h2;

	vector<ll> H(n), P(n), H1(n);

	H[0] = A[0];
	H1[0] = 1;
	P[0] = 1;
	for (i = 1; i < n; ++i) {
		H[i] = ((H[i - 1] * M) % N + A[i]) % N;
		H1[i] = ((H1[i - 1] * M) % N + (i + 1)) % N;
		P[i] = (P[i - 1] * M) % N;
	}

	auto get_hash = [&](ll left, ll right) {
		if (left > right)
			return 0LL;
		if (left == 0)
			return H[right];
		return (N + H[right] - H[left - 1] * P[right - left + 1] % N) % N;
		};
	auto get_hash1 = [&](ll left, ll right) {
		if (left > right)
			return 0LL;
		if (left == 0)
			return H1[right];
		return (N + H1[right] - H1[left - 1] * P[right - left + 1] % N) % N;
		};

	if (B.size() == 1) {
		x = B[0].first;
		y = B[0].second;
		for (i = x + 1; i <= y; ++i) {
			h1 = get_hash(x, i - 1);
			h2 = get_hash(i, y);
			if ((h2 * P[i - x] % N + h1) % N == get_hash1(x, y)) {
				cout << x + 1 << ' ' << i - x << '\n';
				cout << i + 1 << ' ' << y - i + 1 << '\n';
				return;
			}
		}
		cout << "-1\n";
		return;
	}

	if (B.size() == 2) {
		vector<ll> W;
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
		for (i = 0; i < n; ++i)
			if (W[i] != i + 1) {
				cout << "-1\n";
				return;
			}
		if (B[1] > B[0])
			swap(B[1], B[0]);
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