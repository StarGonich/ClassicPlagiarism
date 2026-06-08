#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define int long long

void solve() {
    int n; cin >> n;

    int three = n / (4 * 5 * 6 / 2);
    int two1 = n / (4 * 5) - three, two2 = n / (4 * 6 / 2) - three, two3 = n / (5 * 6) - three;
    cout << n / 4 - (two1 + two2) - three + n / 5 - (two1 + two3) - three + n / 6 - (two2 + two3) - three << "\n";

    /*
    int ans2 = 0;
    for (int i = 1; i <= n; ++i) {
        int sum = (i % 4 == 0);
        sum += (i % 5 == 0);
        sum += (i % 6 == 0);
        if (sum == 1) {
            ++ans2;
        }
    }
    cout << ans2 << "\n";*/
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Q = 1;
    // cin >> Q;
    while (Q--) {
        solve();
    }
}
