#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define int long long

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto& i: arr) cin >> i;
    vector<int> drr(n);
    for (auto& i: drr) cin >> i;

    int k; cin >> k; --k;
    int left = arr[k] - drr[k], right = arr[k] + drr[k];
    int li = k - 1, ri = k + 1;
    while (true) {
        bool did = false;
        while (li >= 0 && arr[li] >= left) {
            left = min(left, arr[li] - drr[li]);
            right = max(right, arr[li] + drr[li]);
            --li;
            did = true;
        }
        while (ri < n && arr[ri] <= right) {
            left = min(left, arr[ri] - drr[ri]);
            right = max(right, arr[ri] + drr[ri]);
            ++ri;
            did = true;
        }
        if (!did) {
            break;
        }
    }

    cout << ri - li - 1 << "\n";
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
