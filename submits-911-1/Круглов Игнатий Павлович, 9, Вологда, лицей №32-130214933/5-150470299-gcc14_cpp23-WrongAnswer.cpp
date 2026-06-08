#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1'000'000'000;

void solve() {
    int k, n, m;
    cin >> k >> n >> m;
    if (k == 2) {
        int l = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x;
                cin >> x;
                if (x == 1) {
                    l == 1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x;
                cin >> x;
            }
        }
        if (l == 1) {
            cout << 2 << " " << 1;
            return;
        }
        else {
            cout << 1 << " " << 2;
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("", "r", inout)

    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
}
