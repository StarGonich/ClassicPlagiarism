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
int q(int x) {
    cout << x << " B" << endl;
    int cur;
    cin >> cur;
    if (cur == -1) exit(0);
    return cur;
}
void solve() {
    int step = 210 / 15;
    int cur = 210;
    int loscnt = 0;
    int st = step;
    while(cur < 1000) {
        if (loscnt == 0) {
            step = cur / 15;
            st = step;
        } else if (loscnt == 3) {
            st = cur;
        }

        int f = q(st);
        if (f == 0) {
            cur -= st;
            loscnt++;
            st *= 2;
        } else {
            cur += st;
            loscnt = 0;
        }
    }
}

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0); 

    #ifdef LOCAL
    // freopen("in", "r", stdin);
    
    #endif
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}