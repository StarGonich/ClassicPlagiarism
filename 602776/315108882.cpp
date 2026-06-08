#include<bits/stdc++.h>
#include <cassert>

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
    int cnt = 0, cur = 210;
    vi st = {15, 40, 155};
    while(true){
        cout << st[cnt] << " R" << endl;
        int res; cin >> res;
        if(res == 0) cur -= st[cnt++];
        else if (res == 1){
            cur += st[cnt];
            cnt = 0;
        }
        else assert(false);

        if(cur >= 1000) break;
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
