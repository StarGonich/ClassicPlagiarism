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
int __gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return __gcd(b % a, a);
}
void solve() {
    cout << fixed;
    cout.precision(15);
    int a,b,c,d,p,q;
    cin >> a >> b >> p >> c >> d >> q;
    if (c == 0) {
        swap(a, c); swap(b, d); swap(p, q);
    }
    if (a % b == 0 && c % d == 0 && a / b == c / d) {
        if (abs(1.0 * p / q - 1.0 * a / b) > 1e-4) {
            cout << "Contradiction";
            return;
        } else {
            cout << "Ambiguity";
            return;
        }
    }

    long double A = a, B = b, C = c, D = d, P = p, Q = q;
    long double y = (C * P - A * Q) / (C * B - A * D);
    long double x = (Q - D * y) / C;
    if (x < 0 || y < 0) {
        cout << "Not positive"; return;
    } else 
        cout << "Success\n" << x * 100.0 << " " << y * 100.0 << endl;   
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