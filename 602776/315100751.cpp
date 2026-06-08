#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back

#ifndef LOCAL
#define cerr                                                                                                           \
	if (0)                                                                                                             \
	cerr
#endif

using namespace std;

typedef unsigned short us;
typedef long long ll;
typedef long double ld;
typedef __int128 lll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

istream &operator>>(istream &in, lll &i)
{
	ll val;
	in >> val;
	i = val;

	return in;
}

ostream &operator<<(ostream &out, lll i)
{
	out << (ll)i;

	return out;
}

template <typename T, typename V> ostream &operator<<(ostream &out, pair<T, V> p);
template <typename T> ostream &operator<<(ostream &out, vector<T> v);
template <typename T, typename C> ostream &operator<<(ostream &out, set<T, C> s);
template <typename T, typename V, typename C> ostream &operator<<(ostream &out, map<T, V, C> m);

template <typename T, typename V> ostream &operator<<(ostream &out, pair<T, V> p)
{
	out << "(" << p.ff << ", " << p.ss << ")";

	return out;
}

template <typename T> ostream &operator<<(ostream &out, vector<T> v)
{
	out << "[";
	for (T &e : v)
		out << e << ", ";
	out << "]";

	return out;
}

template <typename T, typename C> ostream &operator<<(ostream &out, set<T, C> s)
{
	out << "{";
	for (T &e : s)
		out << e << ", ";
	out << "}";

	return out;
}

template <typename T, typename V, typename C> ostream &operator<<(ostream &out, map<T, V, C> m)
{
	out << "{";
	for (auto &e : m)
		out << e << ", ";
	out << "}";

	return out;
}

inline void solve();

signed main()
{

#ifndef LOCAL
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif

	cout << fixed << setprecision(10);

	int t = 1;
	// cin >> t;

	while (t--)
	{
		solve();
		cout << "\n";
	}

	return 0;
}

const ld eps = 1e-9;

inline void solve()
{
	ll a, b, p;
	ll c, d, q;
	cin >> a >> b >> p >> c >> d >> q;

	ld x1 = 0, x2 = 0;

	if (a == 0)
	{
		x2 = (ld)p / b;

		if (c == 0)
		{
			cout << "Contradiction";
			return;
		}

		x1 = (ld)(q - (ld)p * d / b) / c;

		if (x1 < eps || x2 < eps)
		{
			cout << "Not positive";
			return;
		}

		cout << "Success\n";
		cout << x1 * 100 << " " << x2 * 100 << endl;
		return;
	}

	if (a * q - p * c == 0 && a * d - b * c == 0)
	{
		cout << "Ambiguity";
		return;
	}

	if (a * d - b * c == 0)
	{
		cout << "Contradiction";
		return;
	}

	x2 = (ld)(a * q - p * c) / (a * d - b * c);
	x1 = (ld)(p - x2 * b) / a;

	if (x1 < eps || x2 < eps)
	{
		cout << "Not positive";
		return;
	}

	cout << "Success\n";
	cout << x1 * 100 << " " << x2 * 100;
}