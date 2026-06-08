#include<bits/stdc++.h>


using namespace std;
using ull = unsigned long long;
using ll  = long long;
#define int ll
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


const double EPS = 1e-10;
const int INF = 2e9;
const ll INFL = 2e18;

void solve(){
    int n; cin >> n;
    vi a(n), d(n);
    for(int i=0; i < n; i++) cin >> a[i];
    for(int i=0; i < n; i++) cin >> d[i];
    int k; cin >> k; k--;

    int curl = a[k], curr = a[k];
    int l = k, r = k;
    while(1){
        int fl = 1;

        if(l >= 0 && curl <= a[l] && a[l] <= curr){
            curl = min(curl, a[l] - d[l]);
            curr = max(curr, a[l] + d[l]);
            l--, fl = 0;
        }

        if(r < n && curl <= a[r] && a[r] <= curr){
            curl = min(curl, a[r] - d[r]);
            curr = max(curr, a[r] + d[r]);
            r++, fl = 0;
        }

        if(fl) break;

    }
    cout << (r - l - 1) << '\n';
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
