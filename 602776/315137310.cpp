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
	ll a, b, c, k, x, r;
	ll total = 210;
	a = 8;
	b = 17;
	c = 31;
	k = 0;
	srand(time(NULL));
	while (1)
	{
		x = 31;
		if (k == 3)
			x = total;

		if ((rand() + rand() * rand()) % 2 == 0)
			cout << x << " R" << endl;
		else
			cout << x << " B" << endl;
		cin >> r;
		if (r == -1)
			break;
		if (r == 1) {
			total += x;
			k = 0;
		}
		if (r == 0) {
			total -= x;
			k++;
		}
		if (total >= 1000)
			break;

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