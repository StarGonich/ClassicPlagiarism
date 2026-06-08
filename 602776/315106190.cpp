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
using vpi = vector<pii>;

void solve() {
    int n; cin >> n;
    vi a(n);
    for (auto &x : a)
        cin >> x;

    vector<array<int, 4>> seg;

    seg.push_back({a[0], 0, 1, 0});
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i-1] + 1)
            seg.push_back({a[i], i, 1, seg[(int)seg.size() - 1][3] + 1});
        else
            seg[(int)seg.size() - 1][2]++;
    }

    sort(all(seg));

    vpi ans;
    for (int i = 0; i < (int)seg.size(); i++) {
        if (i != seg[i][3])
            ans.push_back({seg[i][1] + 1, seg[i][2]});
    }

    if ((int)ans.size() != 2) {
        cout << -1 << '\n';
        return;
    }

    sort(all(ans));
    for (auto [x, y] : ans)
        cout << x << ' ' << y << '\n';
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
