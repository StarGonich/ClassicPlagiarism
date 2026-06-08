#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e9;


void solve() {
    int n;
    cin >> n;
    if (n > 3) {
        cout << -1;
    } else {
        if (n == 3) {
            cout << "6\n 1 2 3";
        } else {
            if (n == 2) {
                cout << -1;
            } else {
                cout << "1\n 1";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}
