#include<bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ll  = long long;
#define pb push_back
#define fi first 
#define se second
#define vi vector<int> 
#define vl vector<ll> 
#define vvi vector<vi> 
#define vvl vector<vl> 
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vii vector<pii> 
#define vll vector<pll> 
#define vvii vector<vii>
#define vvll vector<vll>
#define all(x) begin(x), end(x)
#define sz(x) int(x.size())

#ifdef LOCAL
#include "/home/alyoksi/CP/template/debug.h"
#else
#define deb(x)
#endif

const double EPS = 1e-10;
const int INF = 2e9;
const ll INFL = 2e18;

void solve(){
    ll n; cin >> n;
    ll ans = n/4 + n/5 + n/6 - 2*(n/lcm(4, 5)) - 2*(n/lcm(4, 6)) - 2*(n/lcm(5, 6)) + 3*(n / lcm(4, lcm(5, 6)));
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);

    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int T = 1;
    // cin >> T;

    while(T--) solve();

    return 0;
}
