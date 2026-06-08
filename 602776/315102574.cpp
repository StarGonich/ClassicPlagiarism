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

	int t = 1;
	// cin >> t;

	while (t--)
	{
		solve();
		cout << "\n";
	}

	return 0;
}

inline void solve()
{
	int n;
	cin >> n;

	vector<array<ll, 2>> v(n);
	for (auto &[x, d] : v)
		cin >> x;
	for (auto &[x, d] : v)
		cin >> d;

	int k;
	cin >> k;

	ll l = v[k][0] - v[k][1], r = v[k][0] + v[k][1];
	int li = k - 1, ri = k + 1;
	int cnt = 1;

	while (true)
	{
		bool isOk = false;

		while (li >= 0 && v[li][0] >= l)
		{
			l = min(l, v[li][0] - v[li][1]);
			r = max(r, v[li][0] + v[li][1]);
			cnt++;
			li--;

			isOk = true;
		}

		while (ri < n && v[ri][0] <= r)
		{
			l = min(l, v[ri][0] - v[ri][1]);
			r = max(r, v[ri][0] + v[ri][1]);
			cnt++;
			ri++;

			isOk = true;
		}

		if (!isOk)
			break;
	}

	cout << cnt;
}