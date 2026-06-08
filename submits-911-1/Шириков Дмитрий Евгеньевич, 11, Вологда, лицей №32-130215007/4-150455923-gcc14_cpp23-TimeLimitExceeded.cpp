#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 1e18, x = 0;
    for (ll i = n + 1; i <= n + (n, k); i++) {
        if (ans > (n * i) / __gcd(n, i)) {
            ans = min(ans, (n * i) / __gcd(n, i));
            x = i;
        }
    }
    cout << x;
    return 0;
}
