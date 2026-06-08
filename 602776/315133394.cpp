//#pragma optimizate("O3,unroll-loops,no-stack-protector")
//#pragma target("sse4.2,bmi,bmi2,fma,popcnt,lzcnt,avx,avx2,abm")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include<fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <stack>
#include <memory>
#include <cmath>

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using vll = std::vector<ll>;
using ldouble = long  double;
using vpll = std::vector<pll>;
//#define cin fin
//#define cout fout




using namespace std;
const ll INF = 4e18;
const ll mod1 = 998244353;
const ll mod2 = 998244357;
const ll p1 = 373;
const ll p2 = 273;
const ll msize = 1e6;
const ll N = 1e6;
const ll inf = 2e18;

template<class T, class R>istream& operator>>(istream& in, pair<T, R>& a)
{
	in >> a.first >> a.second;
	return in;
}

template<class T>istream& operator>>(istream& in, vector<T>& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		in >> a[i];
	}
	return in;
}

ll gcd(ll a, ll b)
{
	if (a < b)
	{
		swap(a, b);
	}
	if (b == 0)
		return a;
	return gcd(b, a % b);
}



ll  ln(ll x)
{
	ll k = 0;
	while (x > 0)
	{
		k++;
		x /= 2;
	}
	return k - 1;
}

ll eil(ll n)
{
	int result = n;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}


ll bin_pow_m(ll x, ll y, ll mod)
{
	if (y == 0)
		return 1;
	if (y == 1)
	{
		return x % mod;
	}
	if (y % 2)
	{
		return (bin_pow_m(x, y - 1, mod) * x) % mod;
	}
	else
	{

		return bin_pow_m(x * x % mod, y / 2, mod);;
	}
}

struct Hesh
{
public:
	vector<ll> pr1;
	vector<ll> pr2;
	ll size;
	ll h1;
	ll h2;
	Hesh(string s)
	{
		size = s.size();
		pr1.resize(size);
		pr2.resize(size);
		pr1[0] = (s[0] * p1) % mod1;
		pr2[0] = (s[0] * p2) % mod2;
		ll p11 = p1;
		ll p22 = p2;
		for (int i = 1; i < size; i++)
		{
			p11 = (p11 * p1) % mod1;
			p22 = (p22 * p2) % mod2;
			pr1[i] = ((pr1[i - 1] + s[i]) * p1) % mod1;
			pr2[i] = ((pr2[i - 1] + s[i]) * p2) % mod2;
		}
		h1 = pr1[size - 1];
		h2 = pr2[size - 1];
	}
	ll hesh_str1(ll l, ll r)
	{
		if (l == 0)
		{
			return pr1[r];
		}
		else
		{
			return (pr1[r] + mod1 - (bin_pow_m(p1, r - l + 1, mod1) * pr1[l - 1]) % mod1) % mod1;
		}

	}
	ll hesh_str2(ll l, ll r)
	{
		if (l == 0)
		{
			return pr2[r];
		}
		else
		{
			return (pr2[r] + mod2 - (bin_pow_m(p2, r - l + 1, mod2) * pr2[l - 1]) % mod2) % mod2;
		}

	}



};


long long gcd_ext(long long a, long long b, long long& x, long long& y) {

	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long d = gcd_ext(b, a % b, x, y);
	x -= (a / b) * y;
	swap(x, y);
	return d;
}
vll F;

void Fbild(ll n, ll mod)
{
	F.resize(n + 1);
	F[0] = 1;
	for (int i = 1; i < F.size(); i++)
	{
		F[i] = (F[i - 1] * i) % mod;
	}
}


ll C(ll n, ll k, ll mod)
{
	return(((((F[n]) * bin_pow_m(F[k], mod - 2, mod)) % mod) * bin_pow_m((F[n - k]), mod - 2, mod)) % mod);
}


struct point
{
public:
	ldouble x;
	ldouble y;
	bool operator < (const point b)
	{
		if (x <= b.x)
		{
			if (x == b.x)
			{
				if (y < b.y)
					return true;
				else
					return false;
			}
			else
				return true;
		}
		else
			return false;
	}

};
istream& operator>>(istream& in, point& a)
{
	in >> a.x >> a.y;
	return in;

}
ldouble rast(point a, point b)
{
	ldouble x = a.x - b.x;
	ldouble y = a.y - b.y;
	return sqrt(x * x + y * y);
}
ldouble skp(point r, point a, point b)
{
	return (a.x - r.x) * (b.y - r.y) - (a.y - r.y) * (b.x - r.x);
}


vector<point> pohal(vector<point>& p)
{
	sort(p.begin(), p.end());
	vector<point> hal;
	for (auto v : p)
	{
		while (hal.size() >= 2)
		{
			if (skp(hal[hal.size() - 2], hal[hal.size() - 1], v) >= 0)
			{
				hal.pop_back();
			}
			else
				break;
		}
		hal.push_back(v);
	}
	vector<point> nhal = hal;
	hal.clear();
	reverse(p.begin(), p.end());
	for (auto v : p)
	{
		while (hal.size() >= 2)
		{
			if (skp(hal[hal.size() - 2], hal[hal.size() - 1], v) >= 0)
			{
				hal.pop_back();
			}
			else
				break;
		}
		hal.push_back(v);
	}
	for (int i = 1; i < hal.size() - 1; i++)
	{
		nhal.push_back(hal[i]);
	}
	return nhal;
}


vll tf(N + 1);

ll sumtf(ll r)
{
	ll res = 0;
	for (; r > 0; r -= r & -r)
	{
		res += tf[r];
	}
	return res;
}
ll sumtf(ll l, ll r)
{
	return sumtf(r) - sumtf(l - 1);
}

void addtf(ll k, ll x)
{
	for (; k <= N; k += k & -k)
	{
		tf[k] += x;
	}
}


void slove()
{
	ll n = 210;
	ll t = 0;
	ll st = 10;
	ll cnt = 0;
	ll p = 0;
	ll db;
	while (n < 1000)
	{
		cnt++;
		
		//cout << n << endl;
		ll tp;
		if (t == 0)
		{
		
			st = p +n/26;
			db = n / 26;
			cout << st << " B" << endl;
			tp = st;
		}
		if (t == 1)
		{
			tp = p+db;
			cout << tp << " B" << endl;
			
		}
		if (t == 2)
		{
			tp = p+db;
			cout << tp << " B" << endl;
			
		}
		if (t == 3)
		{
			cout << n << " B" << endl;
			tp = n;
		}
		ll z;
		cin >> z;
		if (z == 1)
		{
			n += tp;
			t = 0;
			p = 0;
		}
		else
		{
			if (z == -1)
			{
				t = 0;
				z = z / t;
			}
			t++;
			n -= tp;
			p += tp + db;
		}
	}
}

int main()
{
	//Fbild(1e6, 1e9 + 7);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t = 1;
	//cin >> t;

	while (t--)
	{
		slove();
	}
}