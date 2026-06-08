#include<bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double
#define ll long long
#define pii pair<int, int>
#define vii vector<pii>
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sza(x) (int)x.size()
const int N = 1e5+5;
const int inf = 1e9;
const int mod = 1e9+7;
int dp[2002][2002];
void solve() {
    int n;
    cin >> n;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 2000; j++) {
            for(int k = 1; k * k <= j; k++) {
                dp[i][j] |= dp[i - 1][j - k * k];
            }
        }
    }
    for(int i = 1; i * i <= 2000; i++) {
        if(dp[n][i * i]) {
            int cur = i * i;
            int ind = n;
            for(int i = n; i > 0; i--) {
                for(int k = 1; k * k <= cur; k++) {
                    if(dp[i - 1][cur - k * k]) {
                        cout << k << " ";
                        cur -= k * k;
                        break;
                    }
                }
            }
            cout << i << endl;
            return;
        }
    }
    cout << -1;
}

signed main() { 
    ios_base::sync_with_stdio(0);
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
