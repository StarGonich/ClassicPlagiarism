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

void solve() {
    int n;
    cin >> n;
    int k = 0;
    for(int i = 1; i <= 10000; i++) {
        if((i * i - n) % 3 == 0) {
            k = i;
            break;
        }
    }
    if(!k) {
        cout << -1 << endl;
        return;
    }
    int cnt4 = (k * k - n) / 3;
    int cnt1 = k * k - 4 * cnt4;
    for(int i = 0; i < cnt1; i ++) {
        cout << 1 << " ";
    }
    for(int i = 0; i < cnt4; i++) {
        cout << 2 << " ";
    }
    cout << k << endl;
    cout << "\n";

}

signed main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
    // freopen("in", "r", stdin);
    #endif
    int t = 1;
    // cin >> t;
    while(t--) { 
        solve();
    }
} 
