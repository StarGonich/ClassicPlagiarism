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
	int n, i, j;

	cin >> n;
	if (n == 2) {
		cout << "3 4 5\n";
		return;
	}
	int left, right, mid, x;
	left = 1;
	right = n;
	while (right - left > 1)
	{
		mid = (right + left) / 2;
		if (mid * mid < n)
			left = mid;
		else
			right = mid;
	}
	if (right * right <= n)
		x = right;
	else
		x = left;

	if (x * x != n) {
		cout << "-1\n";
		return;
	}

	for (i = 0; i < n; ++i)
		cout << "1 ";
	cout << x << '\n';
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