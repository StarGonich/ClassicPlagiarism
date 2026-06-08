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

int a[SZ];
int b[SZ];
vector<pair<int, int>>pos;
void solve(){
    int s = 210;
    int cntl = 0;
    int last = s / 15;
    int cnt = 0 ;
    while(s < 1000 && cnt < 100){
        int st = 0;
        cnt++;
        if(cntl == 3) st = s;
        if(cntl == 2) st = s / 3;
        if(cntl == 1) st = s / 5;
        if(cntl == 0) st = s / 9;
        cout << st << " " << "R" << endl;
        int gg; cin  >> gg;
        if(gg == 1) {
            s += st  * 2;
            cntl = 0;
        }else{
            s -= st;
            cntl++;
        }
    }

}

signed main()
{
    #ifdef LOCAL
        // freopen("input.txt", "r", stdin);
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
        cout << '\n';
    }
}