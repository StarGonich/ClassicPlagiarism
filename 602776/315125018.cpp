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
const int tmp = 210/15;
void solve() {
    int cur = 210;
    int los = 0;
    int st = tmp;
    while(cur < 1000) {
        int x = 0;
        if (los == 3) {
            x = cur;
        } else {
            x = st;

        }
        cur -= x;
        int ans = q(x);
        if (ans == 0) {
            los++;
            st = x * 2;
        } else {
            cur += x * 2;
            los = 0;
            st = tmp;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
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