#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long 
#define f(i, n) for (int i = 0; i < (int)(n); ++i)
#define F(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define all(x) (x).begin(), (x).end()
// #define double long double

const int INF = 1e18;
const int mod = 1e9 + 7;
const double eps = 1e-7;
const int SZ = 2e6 + 5;
const double long PI = acos(-1);

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (unsigned long long)rng() % B;
}

int dp[SZ];
int pref[SZ];
void solve(){
    int n; cin >> n;
    int sum = 0;
    F(i, 1, n) {
        dp[i] = sum - dp[i - 1] + 1 + mod;
        dp[i] %= mod;
        sum += dp[i];
        sum  %= mod;
        pref[i] = sum;
    }
    int ans = 0;
    pref[0] = 1;
    F(i, 1, n - 1){
        int l = i - 2;
        int r = n - i - 2;
        // cout << l << " " << r << endl;
        ans += (pref[max(0ll, l)] * pref[max(0ll, r)] + 1) % mod;
        if(max(0ll, l) == 0 && max(0ll, r) == 0) ans = (ans + mod - 1);
        ans %= mod;
        // cout << pref[max(0ll, r)] * pref[max(0ll, r)] + 1 << endl;
    }
    cout << ans;
}

signed main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cout << fixed;
    // cout.precision(7);
    // cin >> T;
    while (T--){
        solve();
        cout << '\n';
    }
}