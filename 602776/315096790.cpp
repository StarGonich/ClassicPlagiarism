#include <bits/stdc++.h>

#define fi first
#define se second
#define all(x) x.begin(), x.end()

#define int ll

using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

void solve() {
    int n; cin >> n;

    int ans = n / 4 - n / (5*4) - n / 12 + 2 * n / 60;
    ans += n / 5 - n / (5*4) - n / (5*6) + 2 * n / 60;
    ans += n / 6 - n / 12 - n / 30 + 2 * n / 60;

    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t --> 0) {
        solve();
        cout << '\n';
    }

    return 0;
}
