#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define int long long

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto& i: arr) {
        cin >> i;
        --i;
    }

    vector<int> idxs(n);
    for (int i = 0; i < n; ++i) {
        idxs[arr[i]] = i;
    }

    int left1 = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != i) {
            left1 = i;
            break;
        }
    }
    if (left1 == -1) {
        cout << "-1\n";
        return;
    }
    int right2 = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] != i) {
            right2 = i;
            break;
        }
    }

    int left2 = idxs[left1], right1 = idxs[right2];

    if (left1 <= right1 && left2 <= right2 && (left2 > right1 || right2 < left1)) {
        cout << left1 + 1 << " " << right1 - left1 + 1 << "\n";
        cout << left2 + 1 << " " << right2 - left2 + 1 << "\n";
    } else {
        cout << "-1\n";
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
