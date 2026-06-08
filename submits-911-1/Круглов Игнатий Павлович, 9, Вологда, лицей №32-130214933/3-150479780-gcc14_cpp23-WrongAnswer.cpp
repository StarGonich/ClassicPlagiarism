#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int t;
    cin >> t;
    ll sum = 0;
    deque<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        sum += r - l;
        a.push_back({l, r});
        if (r - l > t && i == 0) {
            cout << (l + t - 1) - 3600;
            return;
        }
        if (sum > t) {
            for (int i = 0; i < a.size(); ++i) {
                if (a[i].second < l - 3600 + 1) {
                    sum -= a[i].second - a[i].first;
                    a.pop_front();
                }
                else {
                    break;
                }
            }
            if (sum <= t) {
                continue;
            }
            cout << (l + (t + 1 - (sum - (r - l))) - 1) - 3600 + 1 ;
            return;
        }
    }
    cout << -1;
    return;
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
