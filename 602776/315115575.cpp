#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define PI 3.1415926535897932

#define int long long
const int MOD = 1e9 + 7;

void solve() {
    cout << fixed << setprecision(15);

    int n; cin >> n;
    if (n == 1) {
        cout << "1 1\n";
        return;
    }
    if (n == 2) {
        cout << "3 4 5\n";
        return;
    }
    if (n == 3) {
        cout << "2 2 1 3\n";
        return;
    }

    if (n % 2 == 0) {
        cout << n / 2 - 1 << " ";
        for (int i = 1; i < n; ++i) {
            cout << "1 ";
        }
        cout << n / 2 << "\n";
        return;
    }
    cout << (n + 3) / 2 - 1 << " ";
    for (int i = 1; i < (n + 3) - 4; ++i) {
        cout << "1 ";
    }
    cout << "2 ";
    cout << (n + 3) / 2 << "\n";

    /*
    for (int i = 3; i <= 1e9; ++i) {
        if (i * i < n) continue;
        if (i * i % 6 == n % 6) {
            int cnt1 = i * i, cnt2 = 0;
            int x = i * i;
            while (x > n) {
                x -= 6;
                cnt1 -= 8;
                cnt2 += 2;
            }
            for (int j = 0; j < cnt1; ++j) {
                cout << "1 ";
            }
            for (int j = 0; j < cnt2; ++j) {
                cout << "2 ";
            }
            cout << i << "\n";
            return;
        }
    }*/
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
