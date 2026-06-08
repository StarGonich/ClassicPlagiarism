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
    cout << fixed;
    cout.precision(15);
    long double a,b,c,d,p,q;
    cin >> a >> b >> p >> c >> d >> q;
    if (a == 0 && c == 0 || b == 0 && d == 0 || a == c && b == d && p == q) {
        cout << "Ambiguity"; return;
    }
    if (c * b - a * d == 0 || c == 0 || a == c && b == d && p != q) {
        cout << "Contradiction"; return;
    }
    long double y = (c * p - a * q) / (c * b - a * d);
    long double x = (q - d * y) / c;

    if (x > 0 && y > 0) 
        cout << "Success\n" <<  x * 100.0 << " " << y * 100.0 << endl;
    else 
        cout << "Not positive";
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