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
    vll A(n + 1);
    for (ll i = 1; i <= n; ++i)
    {
        cin >> A[i];
    }
    vll Pos(n + 1);
    for (ll i = 1; i <= n; ++i)
    {
        Pos[A[i]] = i;
    }
    bool f = true;
    ll pos = -1;
    for (ll i = 1; i <= n && f; ++i)
    {
        if (i != A[i])
        {
            pos = i;
            f = false;
        }
    }
    if (f)
    {
        cout << -1;
        return;
    }
    ll fin = pos;
    bool t = true;
    for (ll i = pos + 1; i <= n && t; ++i)
    {
        if (A[i] == A[i - 1] + 1)
        {
            fin = i;
        }
        else
        {
            t = false;
        }
    }
    vll Ans(4);
    Ans[0] = pos;
    Ans[1] = fin - pos + 1;
    vll Get(n + 1);
    for (ll i = 1; i <= n; ++i)
    {
        Get[i] = A[i];
    }
    for (ll i = A[pos]; i <= A[fin]; ++i)
    {
        Get[i] = i;
    }
    ll need = Pos[pos];
    ll fn = need;
    t = true;
    for (ll i = need + 1; i <= n && t; ++i)
    {
        if (A[i] == A[i - 1] + 1)
        {
            fn = i;
        }
        else
        {
            t = false;
        }
    }
    for (ll i = A[need]; i <= A[fn]; ++i)
    {
        Get[i] = i;
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (Get[i] != i)
        {
            cout << -1;
            return;
        }
    }
    Ans[2] = need;
    Ans[3] = fn - need + 1;
    cout << Ans[0] << ' ' << Ans[1] << '\n' << Ans[2] << ' ' << Ans[3];
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1; //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}