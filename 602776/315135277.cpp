#include<bits/stdc++.h>
#include <numeric>

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

ll root(ll n){
    if(n == 0) return 0;
    ll l = 1, r = n;
    while(l + 1 < r){
        ll m = (l + r) / 2;
        if(m * m > n) r = m;
        else l = m;
    }
    return l;
}

void solve(){
    int n; cin >> n;
    if(n == 1){
        cout << "1 1\n";
        return;
    }
    if(n == 2){
        cout << "3 4 5\n";
        return;
    }

    for(ll p = 1; p <= 1000; p++){
        if(p*p <= n-1) continue;
        ll r = root(p*p - (n-1));
        if(r == 0 || r*r != (p*p - (n-1))) continue;

        // deb(p*p - (n-1), r*r);

        for(int i = 0; i < n-1; i++)
            cout << 1 << ' ';
        cout << r << ' ' << p << '\n';
        return;
    }

    for(ll p = 1; p <= 1000; p++){
        if(p*p <= n+2) continue;
        ll r = root(p*p - (n+2));
        if(r == 0 || r*r != (p*p - (n+2))) continue;

        cout << 2 << ' ';
        for(int i = 4; i < n+2; i++)
            cout << 1 << ' ';
        cout << r << ' ' << p << '\n';
        return;
    }
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
