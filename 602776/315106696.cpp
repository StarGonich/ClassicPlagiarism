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

const ll A = 31;
vector<ll> pA(1005);
const ll MOD = 1e9 + 7;

ll hs(string &s)
{
	ll res = 0;
	for (int i = 0; i < s.size(); i++)
		res = (res + (s[i] - 'A') * pA[i] % MOD) % MOD;

	return res;
}

inline void solve()
{
	pA[0] = 1;
	for (int i = 1; i < 1005; i++)
		pA[i] = pA[i - 1] * A % MOD;

	int t;
	cin >> t;

	if (t == 1)
	{
		string s;
		cin >> s;

		ll h = hs(s);

		string sh = "";
		while (h > 0)
		{
			sh.push_back(h % 26 + 'A');
			h /= 26;
		}
		while (sh.size() < 10)
			sh.push_back('A');
		reverse(sh.begin(), sh.end());

		cout << s << s << sh;
	}
	else
	{
		string s;
		cin >> s;

		int n = s.size() - 10;

		string sh = s.substr(n);
		ll h = 0;
		for (char c : sh)
			h = (h * 26 % MOD + (c - 'A')) % MOD;

		string s1 = s.substr(0, n / 2), s2 = s.substr(n / 2, n / 2);
		ll h1 = hs(s1), h2 = hs(s2);

		if (h != h1 && h != h2)
			cout << s1;
		else if (h != h2)
			cout << s1;
		else
			cout << s2;
	}
}