#include<algorithm>
#include<bitset>
#include<climits>
#include<iomanip>  // cout << setprecision(...) <<  fixed;
#include<iostream>
#include<map>
#include<math.h>
#include<queue>
#include<random>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include <cassert>
// #include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef queue<ll> qll;
typedef set<ll> sll;
typedef const ll cll;
typedef const ld cld;
#define ff first
#define ss second
#define pb push_back
#define FOR(i, start, finish) for(int i = start; i < finish; ++i)
#define FORD(i, start, finish) for(int i = start; i >= finish; --i)

cld pi = atan2l(0, -1);
cll mod = 1e9 + 7;
cll MOD = 998244353;
cld EPS = 1e-7;
cll INF = 4 * (ll)1e18;

mt19937_64 rnd(random_device{}());

ll binpow(ll a, ll b, ll mm) // a ^ b % mm
{
	ll res = 1;
	while (b)
	{
		if (b & 1) {
			res *= a;
			res = res % mm;
		}
		a *= a;
		a = a % mm;
		b >>= 1;
	}
	return res % mm;
}
ll GCD(ll a, ll b)
{
	while (b != 0)
	{
		ll c = a % b;
		a = b;
		b = c;
	}
	return a;
}
ll LCM(ll a, ll b)
{
	return a / GCD(a, b) * b;
}


void solve() {
	ll n;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return;
	}
	else if (n == 2) {
		cout << 1;
		return;
	}
	else if (n == 3) {
		cout << 2;
		return;
	}
	vector<ll> dp1(n + 1);
	dp1[0] = 0; dp1[1] = 1;
	FOR(i, 2, n + 1) {
		dp1[i] = dp1[i - 1] + dp1[i - 2] + 1;
		dp1[i] %= mod;
	}
	ll ans = (dp1[n - 3] + dp1[n - 4]) * 2;
	ans %= mod;
	FOR(i, 3, n - 2) {
		ans += (dp1[n - i - 2] * dp1[i - 2]) % mod;
		ans %= mod;
		ans += dp1[n - i - 2];
		ans %= mod;
		ans += dp1[i - 2];
		ans %= mod;
	}
	ans += n - 1;
	ans %= mod;
	cout << ans;
}
/*


*/

int main()
{
	//	freopen("unionday.in", "r", stdin);
	//	freopen("unionday.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll tests = 1;
	//cin >> tests;
	FOR(test, 0, tests)
	{
		solve();
	}
}