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
#define endl '\n'

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
	n -= 1;
	ll ans = 0;
	ans += n / 4;
	ans += n / 5;
	ans += n / 6;
	ans -= n / 20;
	ans -= n / 12;
	ans -= n / 30;
	cout << ans;
}
/*
4 6

12 24 

6 12 18 24 30 36 



4 5 6 8 10 12 15
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