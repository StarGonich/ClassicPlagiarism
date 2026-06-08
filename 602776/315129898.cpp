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
//#define int long long
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
const long double eps = 0.0000000000001;
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
void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << "1 1";
        return;
    }
    if (n == 2)
    {
        cout << "3 4 5";
        return;
    }
    if (n == 3)
    {
        cout << "1 2 2 3";
        return; 
    }
    if ( n == 5)
    {
        cout << "2 2 2 2 3 5";
        return;
    }
    if (n % 3 == 1)
    {
        vll St = { 1 };
        vll St2 = { 1 };
        while (St.back() <= n)
        {
            St.push_back(St.back() * 4);
            St2.push_back(St2.back() * 2);
        }
        ll ne = St.size() - 2;
        ll ost = n - St[ne];
        for (ll i = 0; i < ost / 3; ++i)
        {
            cout << "1 1 1 1 ";
        }
        for (ll i = 0; i < n - (ost / 3) * 4; ++i)
        {
            cout << 2 << ' ';
        }
        cout << St2[ne + 1];
        return;
    }
    if (n % 3 == 0)
    {
        if (n == 6)
        {
            cout << "1 1 1 1 1 2 3";
            return;
        }
        n -= 5;
        vll St = { 1 };
        vll St2 = { 1 };
        while (St.back() <= n)
        {
            St.push_back(St.back() * 4);
            St2.push_back(St2.back() * 2);
        }
        ll ne = St.size() - 2;
        ll ost = n - St[ne];
        for (ll i = 0; i < ost / 3; ++i)
        {
            cout << "1 1 1 1 ";
        }
        for (ll i = 0; i < n - (ost / 3) * 4; ++i)
        {
            cout << 2 << ' ';
        }
        ll side = St2[ne] * 2;
        for (ll i = 0; i < 5; ++i)
        {
            cout << side / 2 << ' ';
        }
        cout << side + side / 2;
        return;
    }
    if (n == 8)
    {
        cout << "1 1 1 1 1 1 1 3 4";
        return;
    }
    vll St = { 7 };
    vll Stn = { 1 };
    vll St2 = { 1 };
    --n;
    while (St.back() <= n)
    {
        St.push_back(St.back() * 4);
        Stn.push_back(Stn.back() * 4);
        St2.push_back(St2.back() * 2);
    }
    ll ne = St.size() - 2;
    ll ost = n - St[ne];
    for (ll i = 0; i < ost / 3; ++i)
    {
        cout << "1 1 1 1 ";
    }
    for (ll i = 0; i < n - (ost / 3) * 4; ++i)
    {
        cout << 2 << ' ';
    }
    ll sideli = St2[ne] * 2;
    cout << 3 * sideli << ' ' << 4 * sideli;
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1; //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}