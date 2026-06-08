#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define PI 3.1415926535897932

#define int long long
const int MOD = 1e9 + 7;
const int INF = 1e15;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (auto& i: arr) cin >> i;
    arr[n - 1] = 0;

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c; --a; --b;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    vector<pair<int, int>> dt(n);
    for (int i = 0; i < n; ++i) {
        dt[i] = {arr[i], i};
    }
    sort(rall(dt));
    vector<int> dp(n, INF); dp[0] = 0;
    vector<int> buy_for(n, 0);
    vector<vector<int>> chains(n); chains[0] = {0};
    vector<int> pr0(n, -1);
    bool was0 = false;
    for (int i = 0; i < n; ++i) {
        if (dt[i].second == 0) {
            was0 = true;
            continue;
        }
        if (!was0) continue;
        int v0 = dt[i].second;
        vector<int> dist(n, INF); dist[v0] = 0;
        vector<int> pr(n, -1);
        set<pair<int, int>> qrr = {{0, v0}};
        while (!qrr.empty()) {
            auto [dv, v] = *qrr.begin(); qrr.erase(qrr.begin());
            for (auto [u, c]: graph[v]) {
                if (dv + c < dist[u]) {
                    qrr.erase({dist[u], u});
                    dist[u] = dv + c;
                    pr[u] = v;
                    qrr.insert({dist[u], u});
                }
            }
        }
        for (int j = 0; j < i; ++j) {
            int u0 = dt[j].second;
            int can = dp[u0] + dt[j].first * dist[u0];
            if (can < dp[v0]) {
                dp[v0] = can;
                pr0[v0] = u0;
            }
        }
        if (pr0[v0] != -1) {
            buy_for[v0] = dist[pr0[v0]];
            for (int v = pr[pr0[v0]]; v != -1; v = pr[v]) {
                chains[v0].push_back(v);
            }
            reverse(all(chains[v0]));
        }
    }

    int res = dp[n - 1];
    if (res == INF) {
        cout << "-1\n";
        return;
    }
    cout << res << "\n";

    vector<int> way;
    vector<int> buy(n, 0);
    for (int v = n - 1; v >= 0; v = pr0[v]) {
        for (auto u: chains[v]) {
            way.push_back(u);
        }
        if (pr0[v] != -1) {
            buy[pr0[v]] = buy_for[v];
        }
    }
    reverse(all(way));
    cout << way.size() << "\n";
    for (auto v: way) {
        cout << v + 1 << " " << buy[v] << "\n";
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Q = 1;
    // cin >> Q;
    while (Q--) {
        solve();
    }
}
