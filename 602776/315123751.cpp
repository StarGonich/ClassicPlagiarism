//#include<udacha$$$>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<iomanip>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<iterator>
#include<bitset>
#include<random>
#include<list>
#include<cstdio>
#include<ctime>
#include<random>
#include<cstdint>
#include<cstdlib>
#include<numeric>
#include<cctype>
#include<math.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
//#pragma GCC warning "deprecated"
using namespace std;
#define ull unsigned long long
#define ll long long
#define int long long
#define vii vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vll vector<ll>
#define dl double
#define ldl long double
#define pll pair<ll, ll>
#define vpll vector<pll>
#define forn(i, n) for(ll i = 0; i < n; ++i)
#define forx(i, x, n) for (ll i = 0;i <= n;++i)
#define forb(n, i) for(ll i = n - 1;i >= 0;--i)
#define sz(A) (ll)A.size()
#define fst first
#define snd second
#define emp(A) A.empty()
#define vvll vector<vll>
#define all(a) (a).begin(), (a).end()
#define debug(x) cout << "x: " << x << '\n'; 
const long double eps = 0.000000000001;
const ll mod = 998244353;
const ll llinf = 1e16;
const long double pi = acos(-1);

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll binPow(ll x, ll y) {
	if (y == 0) {
		return 1ll;
	}

	if (y == 1) {
		return x;
	}

	if (y % 2 == 0) {
		int t = binPow(x, y / 2);
		return (t * t);
	}

	return (x * binPow(x, y - 1));
}
inline void solve() {
	srand(time(0));
	int cur = 210;
	int cnt = 0;
	int f = rand()%2;
	int t = 16;
	int k = 100;
	while (k--) {
		if (cnt == 3) {
			cout << cur << "R" << endl;
			int res; cin >> res;
			cur *= 2;
			cnt = 0;
		}
		else if (cnt < 3){
			cout << cnt*min(t,cur) << "R" << endl;
			int res; cin >> res;
			if (res==1) {
				cnt = 0;
				res += 2 * cnt * min(t, cur);
			}
			else if (res == 0) {
				++cnt;
				res -= cnt*min(t, cur);
			}
			else {
				return;
			}
		}
		if (cur >= 1000) {
			return;
		}
		--k;
	}
}

signed main() {
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll t = 1; //cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}