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
	ld a, b, c, d, p, q;
	cin >> a >> b >> p >> c >> d >> q;
	
	if (
		   (a == c && b == d && p != q) 
		|| (a == 0 && b == 0 && p != 0) 
		|| (c == 0 && d == 0 && q != 0)) {
		cout << "Contradiction";
	}
	else if (a == c && b == d && p == q ||
		(a == 0 && c == 0) || 
		(b == 0 && d == 0) ||
		(a == 0 && b == 0) || 
		(c == 0 && d == 0) ||
		(c / a == d / b && d / b == q / p)
		) {
		cout << "Ambiguity";
	}
	else if (a == 0 && d == 0) {
		ld tr = q / c;
		ld td = p / b;
		if (tr < 0 || td < 0) {
			cout << "Not positive";
		}
		else {
			cout << "Success" << endl;
			cout << tr * 100 << " " << td * 100;
		}
	}
	else if (b == 0 && c == 0) {
		ld tr = p / a;
		ld td = q / d; 
		if (tr < 0 || td < 0) {
			cout << "Not positive";
		}
		else {
			cout << "Success" << endl;
			cout << tr * 100 << " " << td * 100;
		}
	}
	else if (a == 0) {
		ld td = p / b;
		ld tr = (q - d * td) / c;
		if (tr < 0 || td < 0) {
			cout << "Not positive";
		}
		else {
			cout << "Success" << endl;
			cout << tr * 100 << " " << td * 100;
		}
	}
	else if (b == 0) {
		ld tr = p / a;
		ld td = (q - c * tr) / d;
			if (tr < 0 || td < 0) {
				cout << "Not positive";
			}
			else {
				cout << "Success" << endl;
				cout << tr * 100 << " " << td * 100;
			}
	}
	else if (c == 0) {
		ld td = q / d;
		ld tr = (p - b * td) / a;
		if (tr < 0 || td < 0) {
			cout << "Not positive";
		}
		else {
			cout << "Success" << endl;
			cout << tr * 100 << " " << td * 100;
		}
	}
	else if (d == 0) {
		ld tr = q / c;
		ld td = (p - a * tr) / b;
		if (tr < 0 || td < 0) {
			cout << "Not positive";
		}
		else {
			cout << "Success" << endl;
			cout << tr * 100 << " " << td * 100;
		}
	}
	else {
		ld tr, td;
		if ((b * c - d * a) == 0) {

		}
		tr = (ld)(p * c - q * a) / (b * c - d * a);
		td = (ld)(p - b * tr) / a;
		if (tr < 0 || td < 0) {
			cout << "Not positive";
		}
		else {
			cout << "Success" << endl;
			cout << td * 100 << " " << tr * 100;
		}

	}
}
/*

 0 0 100
 0 10 100
 0 0 0
 0 0 10


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