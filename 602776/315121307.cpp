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

unordered_map<int, int> qwe;
void solve(){
    int n; cin >> n;
    // int cnt = 0;
    // F(i, 1, n){
    //     int gg = 0;
    //     if(i % 6 == 0)gg++;
    //     if(i % 4 == 0)gg++;
    //     if(i % 5 == 0)gg++;
    //     if(gg == 1) {
    //         cnt++;
    //         cout << i << endl;
    //     }
    // }
    // cout << cnt << endl;
    int a = n / 4;
    int b = n / 5;
    int c = n / 6;
 
    int d1 = n / 12;
    int d2 = n / 20;
    int d3 = n / 30;
    int d4 = n / 60;
    cout << a + b + c - 2 * d1 - 2 * d2 - 2 * d3 + 3 * d4;
    // if(a + b + c - ans != a + b + c - d1 - d2 - d3 + d4) {cout << n; exit(0);}

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
    // cout << fixed;
    // cout.precision(7);
    // cin >> T;
    while (T--){
        solve();
        // cout << '\n';
    }
}