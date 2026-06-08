#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define int long long

void solve() {
    int streak = 0;
    vector<int> bets = {8, 24, 56, 120};
    int sum = 210;
    while (sum < 1000) {
        int bet = bets[streak];
        cout << bet << " R" << endl;
        int res; cin >> res;
        if (res == -1) {
            return;
        }
        if (res == 0) {
            ++streak;
            sum -= bet;
        } else {
            streak = 0;
            sum += bet;
        }
    }
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
