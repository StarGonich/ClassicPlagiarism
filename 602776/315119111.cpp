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
const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vl dp1(n+1), dp2(n+2);
    dp1[0] = 1, dp1[1] = 2;
    dp2[n+1] = 1, dp2[n] = 2;
    for(int i = 2; i <= n; i++)
        dp1[i] = (dp1[i-1] + dp1[i-2]) % MOD;
    for(int i = n-1; i >= 0; i--)
        dp2[i] = (dp2[i+1] + dp2[i+2]) % MOD;
    ll ans = 0;
    for(int i = 1; i < n; i++){
        (ans += dp1[max(0, i-2)] * dp2[min(n+1, i+3)] % MOD) %= MOD;
    }
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
