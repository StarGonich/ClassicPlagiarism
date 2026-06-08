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
using vvpi = vector<vpi>;
using kek = pair<int, pii>;

const int C = 100;
const int INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;

    vi cost(n);
    vvpi g(n);
    map<pii, int> edge;

    for (auto &x : cost)
        cin >> x;
    
    for (int i = 0; i < m; i++) {
        int v, u, f;
        cin >> v >> u >> f;
        v--; u--;
        g[v].push_back({u, f});
        g[u].push_back({v, f});
        
        edge[{v, u}] = f;
        edge[{u, v}] = f;
    }

    vvi dist(n, vi(C + 1, INF));
    vvpi par(n, vpi(C + 1, {-1, -1}));

    dist[0][cost[0]] = 0;
    priority_queue<kek> q;
    q.push({0, {0, cost[0]}});

    while (!q.empty()) {
        auto [d, vv] = q.top();
        auto [v, c] = vv;
        q.pop();

        d = -d;
        if (d != dist[v][c])
            continue;

        int was = c;
        c = min(c, cost[v]);
        for (auto [to, f] : g[v]) {
            if (dist[to][c] > d + c * f) {
                dist[to][c] = d + c * f;
                par[to][c] = {v, was};
                q.push({-dist[to][c], {to, c}});
            }
        } 
    }

    pii cur = {n-1, 0};
    for (int i = 1; i <= C; i++) {
        if (dist[n-1][i] < dist[n-1][cur.se])
            cur.se = i;
    }

    int mn = dist[n-1][cur.se];
    if (mn == INF) {
        cout << -1 << '\n';
        return;
    }

    vpi ans;
    while (cur.fi != -1) {
        ans.push_back(cur);
        cur = par[cur.fi][cur.se];
    }


    int k = (int)ans.size();
    reverse(all(ans));
    vi vert(C + 1, -1); // для каждой стоимости запомним вершину на пути с этой стоимостью
    vert[cost[0]] = 0;
    for (int i = 1; i < k; i++) {
        int c = ans[i].se;
        int v = ans[i-1].fi;
        if (vert[c] == -1)
            vert[c] = v;
    }

    map<int,int> litres;
    for (int i = 1; i < k; i++) {
        int v = ans[i-1].fi;
        int to = ans[i].fi;
        int c = ans[i].se;
        litres[vert[c]] += edge[{v, to}];
    }

    cout << mn << '\n';
    cout << k << '\n';
    for (auto [x, y] : ans) {
        cout << x+1 << ' ' << litres[x] << '\n';
        litres[x] = 0;
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
