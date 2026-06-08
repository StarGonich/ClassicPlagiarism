#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e9;


void solve() {
    ll n;
    cin >> n;
    if (n == 2) {
        cout << -1;
        return;
    }
    if (n == 1) {
        cout << "1\n1";
        return;
    }
    vector<ll> ans(n);
    ll sum = 3;
    ans[1] = 2;
    ans[0] = 1;
    for (ll i = 2; i < n; ++i) {
        ans[i] = sum;
        sum += ans[i];
    }
    cout << sum <<"\n";
    for (auto a : ans) {
        cout << a << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}
