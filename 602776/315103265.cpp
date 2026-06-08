#include <bits/stdc++.h>

#define fi first
#define se second
#define all(x) x.begin(), x.end()

#define int ll

using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

void solve() {
    int n; cin >> n;
    vi a(n);
    for (auto &x : a)
        cin >> x;

    vi pos, f;
    pos.push_back(0);
    f.push_back(a[0] == 1 ? 1 : 0);

    for (int i = 1; i < n; i++) {
        if (a[i] != a[i-1] + 1) {
            pos.push_back(i);
            f.push_back(a[i] == i+1 ? 1 : 0);
        }
    }

    int cnt = 0;
    for (auto x : f)
        cnt += 1 - x;
    
    if (cnt != 2) {
        cout << -1;
        return;
    }

    for (int i = 0; i < (int)pos.size(); i++) {
        if (f[i] == 0) {
            int l = 0;
            if (i == (int)pos.size() - 1)
                l = n - pos[i];
            else
                l = pos[i+1] - pos[i];
            cout << pos[i] + 1 << ' ' << l << '\n';
        }
    }     
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t --> 0) {
        solve();
    }

    return 0;
}
