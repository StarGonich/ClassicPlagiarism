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
    int cur = 210;
    for(int i = 0; i < 25; i++) {
        int stav = cur / 15;
        int b = 0;
        while(!b){
            assert(cur >= stav);
            cout << stav << " B" << endl;
            cur -= stav;
            stav *= 2;
            cin >> b;
            assert(b != -1);
        }
        // cout << stav << endl;
        cur += stav;
        if(cur >= 1000) {
            break;
        }
    }
    // while(true){}
    // cout << cur << endl;
    assert(cur >= 1000);
}

signed main() { 
    ios_base::sync_with_stdio(0);
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
