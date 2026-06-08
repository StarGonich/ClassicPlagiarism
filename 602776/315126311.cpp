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
    double a, b, p;
    double c, d, q;
    cin >> a >> b >> p;
    cin >> c >> d >> q;

    a /= p, b /= p, p /= p;
    c /= q, d /= q, q /= q;

    if(abs(a - c) < EPS && abs(b - d) < EPS && abs(p - q) < EPS){
        cout << "Ambiguity\n";
        return;
    }

    if(a != 0){
        double tmp = d - b*c/a;
        if(abs(tmp) < EPS){
            cout << "Contradiction\n";
            return;
        }

        double v2 = (q - c/a*p) / tmp;
        double v1 = (p - b*v2) / a;
        if(v1 >= 0 && v2 >= 0){
            cout << "Success\n";
            cout << v1 << ' ' << v2 << '\n';
        }
        else cout << "Not positive\n";
    }
    else{
        double v2 = p / b;
        if(c == 0){
            cout << "Contradiction\n";
            return;
        }
        double v1 = (q - d*v2) / c;
        if(v1 >= 0 && v2 >= 0){
            cout << "Success\n";
            cout << v1 << ' ' << v2 << '\n';
        }
        else cout << "Not positive\n";
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
