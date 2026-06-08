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
vector<int>pos;
void solve(){
    int n; cin >> n;
    F(i, 1, n)
        cin >> a[i];
    int l1 = 0;
    F(i, 1, n){
        l1 = i;
        if(a[i] != i) break;
    }
    if(l1 == 0){
        cout << -1;
        return;
    }
    int r1 = l1;
    F(i, l1 + 1, n){
        if(a[i - 1] + 1 != a[i]) break;
        r1 = i;
    }
    int l2 = 0;
    F(i, r1 + 1, n){
        l2 = i;
        if(a[i] != i) break;
    }
    if(l2 == 0){
        cout << -1;
        return;
    }
    int r2 = l2;
    F(i, l2 + 1, n){
        if(a[i - 1] + 1 != a[i]) break;
        r2 = i;
    }
    int cnt = 1;
    F(i, 1, n){
        if(l1 == i){
            F(j, l2, r2){
                b[cnt] = a[j];
                cnt++;
            }
        }
        if(l1 <= i && i <= r1) continue;
        if(l2 == i){
            F(j, l1, r1){
                b[cnt] = a[j];
                cnt++;
            }
        }
        if(l2 <= i && i <= r2) continue;
        b[cnt] = a[i];
        cnt++;
    }
    F(i, 1, n){
        if(b[i] != i){
            cout << -1;
            return;
        }
    }
    cout << l1 << " " << r1 << endl;
    cout << l2 << " " << r2 << endl;
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
        cout << '\n';
    }
}