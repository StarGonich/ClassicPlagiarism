#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long 
#define f(i, n) for (int i = 0; i < (int)(n); ++i)
#define F(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define all(x) (x).begin(), (x).end()
// #define double long double

const int INF = 1e18;
const int mod = 1e9 + 7;
const double eps = 1e-7;
const int SZ = 2e5 + 5;
const double long PI = acos(-1);

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (unsigned long long)rng() % B;
}

int x[SZ];
int d[SZ];
void solve(){
    int A, B, P; cin >> A >> B >> P;
    int C, D, Q; cin >> C >> D >> Q;
    if(A == C && B == D && P == Q){
        cout << "Ambiguity";
        return;
    }
    double y = (Q * 100.0 * A -  C * P * 100.0) / (A * D - B * C);
    double x = (P * 100.0 - y * B) / A;
    if(x == numeric_limits<double>::infinity() || y == numeric_limits<double>::infinity()){
        cout << "Contradiction";
        return;
    }
    if(x < 0 || y < 0) {
        cout << "Not positive";
        return;
    }
    for(int x = 0.0; x < 10000000; x++){
        double y = (P * 100.0 - A * x / 10.0) / B;
        if(C * x/ 10.0 + y * D == Q * 100.0){
            if(y < 0) {
                cout << "Not positive";
                return;
            }
            cout << "Success" << endl;
            cout << x / 10.0 << " " << y << endl;
            return ;
        } 
    }
    cout << "Contradiction";
}

signed main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cout << fixed;
    cout.precision(7);
    // cin >> T;
    while (T--){
        solve();
        // cout << '\n';
    }
}