#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ll x = n / i;
            if (x *= n + 1 && x <= n + k) {
                cout << x;
                return;
            }
        }
    }
	cout << 1;
}

int main(){
    //ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("", "r", inout)

    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
}
