#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1'000'000'000;

ll nod (ll a, ll b) {
    while (b) {
        if (a > b) {
            swap(a, b);
        }
        b = b % a;
    }
    return a;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll ot, mine = INF;
    for (ll i = n + 1; i <= n + k; ++i) {
        if (mine > (n / nod(n, i)) * i) {
            mine = (n / nod(n, i)) * i;
            ot = i;
        }
    }
    cout << ot;
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
