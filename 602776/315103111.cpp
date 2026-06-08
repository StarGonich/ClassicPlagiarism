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

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<int> d(n);
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }
    int k;
    cin >> k;
    k--;
    int l = k;
    int r = k;
    int ql = x[k] - d[k];
    int qr = x[k] + d[k];
    while(true) {
        int ok = 0;
        if(l >= 0 && x[l] >= ql) {
            ql = min(ql, x[l] - d[l]);
            qr = max(qr, x[l] + d[l]);
            l--;
            ok = 1;
        }
        if(r < n && x[r] <= qr) {
            ql = min(ql, x[r] - d[r]);
            qr = max(qr, x[r] + d[r]); 
            r++;
            ok = 1;
        }
        if(!ok) {
            break;
        }
    }
    cout << r - l - 1 << "\n";
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
