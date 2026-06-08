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
	ll n, i, j, k, w = 0, x, o, m = 100;

	cin >> n;
	if (n == 1) {
		cout << "1 1\n";
		return;
	}
	if (n == 2) {
		cout << "3 4 5\n";
		return;
	}
	for (i = 1; i < m; ++i) {
		for (j = i; j < m; ++j) {
			for (k = j; k < m; ++k) {
				w = i * i + j * j + k * k + n - 3;
				x = (ll)round(sqrt((double)w));
				if (x * x == w) {
					cout << i << ' ' << j << ' ' << k << ' ';
					for (i = 0; i < n - 3; ++i)
						cout << "1 ";
					cout << x << '\n';
					return;
				}
			}
		}
	}

	//n = 100;
	//bool flag = false;
	//for (o = 6; o <= 1000; ++o) {
	//	flag = false;
	//	for (i = 1; i < n; ++i) {
	//		for (j = i; j < n; ++j) {
	//			for (k = j; k < n; ++k) {
	//				w = i * i + j * j + k * k + o - 3;
	//				x = (ll)round(sqrt((double)w));
	//				if (x * x == w) {
	//					flag = true;
	//				}
	//			}
	//		}
	//	}
	//	if (!flag) {
	//		cout << o << '\n';
	//	}
	//}

	
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