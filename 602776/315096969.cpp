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

const int maxN = 2e5 + 5;
const ld eps = 1e-10;
const ld pi = (ld)3.141592653589793238462643383279;

void solve() {
    int n;
    cin >> n;
    vector<int> was (121);
    for (int i = 1 ; i <= 120; i++) {
        if (i % 4 == 0) was[i]++;
        if (i % 5 == 0) was[i]++;
        if (i % 6 == 0) was[i]++;
    }
    int cnt = 0;
    for (int i = 1; i  <= 60; i++) {
        if (was[i] == 1) cnt++;
    }
    cnt *= n / 60;
    for (int i = 1; i <= n % 60; i++) {
        if (was[i] == 1) cnt++;
    }
    cout << cnt;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef LOCAL
    // freopen("in", "r", stdin);
    
    #endif
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}