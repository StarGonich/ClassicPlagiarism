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
	vector<ll> vec(n);
	set<ll> st;
	ll pos = -1;
	ll flag = true;
	FOR(i, 0, n)
	{
		cin >> vec[i];
	}
	ll pos1 = - 1, pos2= -1;
	FOR(i, 0, n) {
		if (vec[i] != i + 1) {
			FOR(j, i + 1, n) {
				if (vec[j] == i + 1) {
					pos2 = j;
					pos1 = i;
					break;
				}
			}
			break;
		}
	}
	if (pos1 == -1 || pos2 == -1) {
		cout << -1 << endl;
		return;
	}
	ll len1 = 1, len2 = 1;
	FOR(i, pos1 + 1, pos2) {
		if (vec[i] == vec[i - 1] + 1) {
			len1++;
		}
		else
			break;
	}
	FOR(i, pos2 + 1, n) {
		if (vec[i] == vec[i -1] + 1) {
			len2++;
		}
		else
			break;
	}
	vector<ll>b;
	FOR(i, 0, pos1) {
		b.push_back(vec[i]);
	}
	FOR(i, pos2, pos2 + len2) {
		b.push_back(vec[i]);
	}
	FOR(i, pos1 + len1, pos2) {
		b.push_back(vec[i]);
	}
	FOR(i, pos1, pos1 + len1) {
		b.push_back(vec[i]);
	}
	FOR(i, pos2 + len2, n) {
		b.push_back(vec[i]);
	}
	FOR(i, 1, n) {
		if (b[i] < b[i - 1]) {
			flag = false;
		}
	}
	if (flag) {
		cout << pos1 + 1 << " " << len1 << endl;
		cout << pos2 + 1 << " " << len2 << endl;
	}
	else {
		cout << -1;
	}
	

}

/*


1 2 3 4 5 6 7
1 5 6 7 2 3 4


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