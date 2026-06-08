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
    int n; cin >> n;
    F(i, 1, n)
        cin >> a[i];
    int cnt = 1;
    int l  = 1;
    while(cnt < n){
        cnt++;
        if(a[cnt - 1]  + 1 != a[cnt]){
            pos.push_back({l, cnt - 1});
            l = cnt;
        }
    }
    pos.push_back({l, cnt});
    if(pos.size() == 1 || pos.size() > 4){
        cout << -1;
        return;
    }
    f(i, pos.size()){
        f(j, pos.size()){
            if(i == j) continue;
            swap(pos[i], pos[j]);
            int cnt = 1;
            for(auto [l, r]: pos){
                F(k, l, r) {
                    b[cnt] = a[k];
                    cnt++;
                }
            }
            int f = 1;
            F(k, 1, n)
                if(b[k] != k) f = 0;
            if(f){ 
                cout << pos[j].first << " " << pos[j].second - pos[j].first + 1 << endl;
                cout << pos[i].first << " " << pos[i].second - pos[i].first + 1 << endl; 
                return;
            }
            swap(pos[i], pos[j]);
        }
    }
    cout << -1;

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