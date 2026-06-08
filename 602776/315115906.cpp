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
    int n; cin >> n;
    vi a(n), p(n);
    for(auto &x : a) cin >> x;
    iota(all(p), 1);

    vii res;
    int l = 0, r = 0;
    for(int i = 1; i < n; i++){
        if(a[i] - a[i-1] == 1) r++;
        else{
            res.pb({l, r});
            l = r = i;
        }
    }
    res.pb({l, r});

    if(sz(res) > 5){
        cout << -1 << '\n';
        return;
    }
    // dib(res);

    int m = sz(res);
    for(int i = 0; i < m; i++){
        for(int j = i+1; j < m; j++){
            vi b(n); int ptr = 0;
            for(int k = 0; k < i; k++){
                for(int ind = res[k].fi; ind <= res[k].se; ind++){
                    b[ptr++] = a[ind];
                }
            }
            for(int ind = res[j].fi; ind <= res[j].se; ind++){
                b[ptr++] = a[ind];
            }
            for(int k = i+1; k < j; k++){
                for(int ind = res[k].fi; ind <= res[k].se; ind++){
                    b[ptr++] = a[ind];
                }
            }
            for(int ind = res[i].fi; ind <= res[i].se; ind++){
                b[ptr++] = a[ind];
            }
            for(int k = j+1; k < m; k++){
                for(int ind = res[k].fi; ind <= res[k].se; ind++){
                    b[ptr++] = a[ind];
                }
            }
            // deb(i, j, b);
            if(b == p){
                cout << res[i].fi+1 << ' ' << (res[i].se - res[i].fi + 1) << '\n';
                cout << res[j].fi+1 << ' ' << (res[j].se - res[j].fi + 1) << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
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
