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
int det(int a, int b, int c, int d) {
    return a * d - b * c;
}
void solve() {
    int a, b, p;
    cin >> a >> b >> p;
    int c, d, q;
    cin >> c >> d >> q;
    if(a == c && a == 0 && p * d != q * b){
        cout << "Contradiction\n";
        return;  
    }
    if(b == d && b == 0 && p * c != q * a){
        cout << "Contradiction\n";
        return;  
    }
    if(a == c && b == d) {
        cout << "Contradiction\n";
        return;
    }
    int dd = det(a, b, c, d);
    if(dd) {
       double x = 1.0 * det(p, b, q, d) / dd * 100;
       double y = 1.0 * det(a, p, c, q) / dd * 100;
       double eps = 1e-9;
       if(x < eps || y < eps) {
        cout << "Not positive\n";
       }
       else cout << "Success\n" << x << " " << y << "\n";
    }
    else {
        cout << "Ambiguity\n";
    }
}

signed main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(6);
    #ifdef LOCAL
    // freopen("in", "r", stdin);
    #endif
    int t = 1;
    // cin >> t;
    while(t--) { 
        solve();
    }
} 
