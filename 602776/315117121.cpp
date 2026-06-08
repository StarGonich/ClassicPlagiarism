#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>

#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vii vector<pii>

#define all(s) s.begin(), s.end()

const int maxN = 1e6 + 5;
const ld eps = 1e-10;
const ld pi = (ld)3.141592653589793238462643383279;
const int mod = 1e9 + 7;
ll dp[maxN];
ll pref[maxN];
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0; return;
    } else if (n == 2) {cout << 1; return;}
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    pref[0] = 0;
    pref[1] = 1;
    pref[2] = 2;
    for (int i = 3; i < maxN; i++) {
        dp[i] = (1 + pref[i - 2]) % mod;
        pref[i] = (pref[i - 1] + dp[i]) % mod;
    }
    ll ans = 0;
    
    for (int i = 1; i < n; i++) {
        // i, i + 1
        int left = max(0, i - 2);
        int right = max(0, n - i - 3 + 1);
        ll cur = 1;
        cur *= (pref[left] + 1);
        cur *= (pref[right] + 1);

        // cout << left << " " << right << " " << cur << endl;
        ans = (ans + cur) % mod;
    }
    cout << ans << endl;
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef LOCAL
    freopen("in", "r", stdin);
    
    #endif
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}