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

bool check(vector<int> &v, int x1, int l1, int x2, int l2)
{
	vector<int> vv;
	for (int i = 0; i < x1; i++)
		vv.push_back(v[i]);
	for (int i = x2; i < x2 + l2; i++)
		vv.push_back(v[i]);
	for (int i = x1 + l1; i < x2; i++)
		vv.push_back(v[i]);
	for (int i = x1; i < x1 + l1; i++)
		vv.push_back(v[i]);
	for (int i = x2 + l2; i < v.size(); i++)
		vv.push_back(v[i]);

	for (int i = 1; i < vv.size(); i++)
		if (vv[i] != vv[i - 1] + 1)
			return false;
	return true;
}

inline void solve()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int &e : v)
		cin >> e;

	vector<int> p(n, 1);
	for (int i = 1; i < n; i++)
	{
		if (v[i] != v[i - 1] + 1)
			p[i] = 1;
		else
			p[i] = p[i - 1] + 1;
	}

	int cnt = count(p.begin(), p.end(), 1);
	if (v[0] == 1)
		cnt--;
	if (v[n - 1] == n)
		cnt--;

	if (cnt > 3 || cnt < 2)
	{
		cout << -1;
		return;
	}

	vector<pair<int, int>> pos;
	for (int i = 1; i < n; i++)
		if (p[i] == 1)
			pos.push_back({i - p[i - 1], p[i - 1]});
	if (v[n - 1] != n)
		pos.push_back({n - p[n - 1], p[n - 1]});

	cout << pos << endl;

	for (int i = 0; i < pos.size(); i++)
		for (int j = i + 1; j < pos.size(); j++)
			if (check(v, pos[i].ff, pos[i].ss, pos[j].ff, pos[j].ss))
			{
				cout << pos[i].ff + 1 << " " << pos[i].ss << "\n" << pos[j].ff + 1 << " " << pos[j].ss;
				return;
			}
}