#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1;
        return;
    }
    else if (n == 1) {
        cout << 5 << "\n";
        cout << 5;
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
