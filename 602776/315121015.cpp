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
    
    int m1 = a * d - b * c;
    int m2 = p * d - b * q;
    int m3 = a * q - c * p;
    if (m1 == 0) {
        if (b * c == a * d) {
            if (p * c == a * q) {
                cout << "Ambiguity";
            } else {
                cout << "Contradiction";
            }
            return;
        } else {
            
        }
    }
    ld x = 100.0 * m2 / m1;
    ld y = 100.0 * m3 / m1;
    if (x >= 0 && y >= 0 ) {
        cout << "Success\n" << x << " " << y << endl;
        return; 
    } else {
        cout << "Not positive" << endl;
    }
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