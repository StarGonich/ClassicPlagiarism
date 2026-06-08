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

	ld r = -1, t = -1;
	ll flag = 4;
	if ((a == c && b == d && p != q) ||
		(a == 0 && b == 0 && p != 0) ||
		(c == 0 && d == 0 && q != 0)) {
		flag = 1;
	}
	else if (b * c - d * a == 0) {
		if (a * d - c * b == 0) {
			flag = 2;
		}
		else {
			t = (p * d - q * b) / (a * d - c * b);
			if (b == 0 && d == 0) {
				flag = 2;
			}
			else if(b != 0){
				r = (p - a * t) / b;
				if (t <= 0 || r <= 0) {
					flag = 3;
				}
			}
			else if (d != 0) {
				r = (q - c * t) / d;
				if (t <= 0 || r <= 0) {
					flag = 3;
				}
			}
		}
	}
	else {
		r = (p * c - q * a) / (b * c - d * a);
		if (a == 0 && c == 0) {
			flag = 2;
		}
		else if(a != 0){
			t = (p - b * r) / a;
			if (t <= 0 || r <= 0) {
				flag = 3;
			}
		}
		else if (c != 0) {
			t = (q - d * r) / c;
			if (t <= 0 || r <= 0) {
				flag = 3;
			}
		}
	}
	if (t == 0 || r == 0) flag = 1;
	switch (flag) {
		case 1:
			cout << "Contradiction";
			break;
		case 2:
			cout << "Ambiguity";
			break;
		case 3:
			cout << "Not positive";
			break;
		case 4:
			cout << "Success" << endl;
			cout << t * 100 << " " << r * 100;
			break;
	}

}
/*
	
	1000

	n * (x ^ 2)

	0, n = 1
	n = n
	n + n ^ n

	1 1 1 1 1 1 1  n
	n


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