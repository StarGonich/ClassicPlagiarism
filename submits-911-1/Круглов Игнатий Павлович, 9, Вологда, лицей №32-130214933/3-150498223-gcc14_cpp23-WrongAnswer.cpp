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
        if (sum > t) {
            ll g = 0;
            for (int i = 0; i < a.size(); ++i) {
                if (a[i].second < r - 3600) {
                    sum -= a[i].second - a[i].first;
                    if (a[i].second >= l - 3600 + 1) {
                        g++;
                    }
                    a.pop_front();
                }
                else {
                    break;
                }
            }
            if (sum <= t) {
                while (g--) {
                    a.pop_front();
                }
                continue;
            }
            ll sum2 = 0;
            ll sume = 0, sy = -1;
            for (auto u : a) {
                    //cout << sume << " " << sum2 << " " << sum << "\n";
                ll x = u.first, y = u.second;
                if (sy == -1) {
                    sume += y - x;
                    sy = y;
                    if (x > l - 3600 + 1) {
                        sum2 += x - (l - 3600 + 1);
                        sume += x - (l - 3600 + 1);
                    }
                }
                else {
                    sume += y - x;
                    sum2 += x - sy;
                    sume += x - sy;
                    sy = y;
                }
                //cout << sume << " " << x << " " << y << " " << sum << " " << sum2 << "\n";
                if (sum2 > t) {
                        sume -= 2 * (y - x);
                    sume -=  sum2 - (t + 1);
                    cout << (l + sume) - 3600;
                    return;
                }
            }
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
