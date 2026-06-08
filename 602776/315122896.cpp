#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 1001;
const int C = 101;
const int INF = 1e9;

vector<pair<int, int>> g[N];

int dist[N][C];
int parent[N][C];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int& i : c) {
        cin >> i;
    }
    for (int i = 0; i < m; i++) {
        int a, b, f;
        cin >> a >> b >> f;
        g[a - 1].emplace_back(b - 1, f);
        g[b - 1].emplace_back(a - 1, f);
    }

    for (int i = 0; i < n; i++) {
        fill(dist[i], dist[i] + C, INF);
        fill(parent[i], parent[i] + C, -1);
    }

    set<pair<int, int>> st;
    st.emplace(0, 0);
    dist[0][c[0]] = 0;

    while (st.size()) {
        auto [d, v] = *(st.begin());
        st.erase(st.begin());

        for (int i = 1; i < C; i++) {
            if (dist[v][c[v]] > dist[v][i]) {
                dist[v][c[v]] = dist[v][i];
                parent[v][c[v]] = parent[v][i];
            }
        }

        for (int i = 1; i <= c[v]; i++) {
            if (dist[v][i] < INF) {
                for (auto [u, f] : g[v]) {
                    if (dist[u][i] > dist[v][i] + f * i) {
                        st.erase({dist[u][i], u});
                        dist[u][i] = dist[v][i] + f * i;
                        st.emplace(dist[u][i], u);
                        parent[u][i] = v;
                    }
                }
            }
        }
    }

    int mn = 0;
    for (int i = 0; i < C; i++) {
        if (dist[n - 1][mn] > dist[n - 1][i]) {
            mn = i;
        }
    }

    if (dist[n - 1][mn] == INF) {
        cout << "-1\n";
        return 0;
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 1; j < C; j++) {
//            if (dist[i][j] < INF) {
//                cout << i << " " << j << ": " << dist[i][j] << " " << parent[i][j] << endl;
//            }
//        }
//    }

    cout << dist[n - 1][mn] << "\n";

    vector<int> path;
    int cur = n - 1;
    int last_price = mn;
    while (cur != -1) {
//        cout << cur << " " << last_price << endl;
        path.push_back(cur);
        int p = parent[cur][last_price];
        if (p == -1) break;
        int w = 0;
        for (auto [u, f] : g[p]) {
            if (u == cur) {
                w = f;
                break;
            }
        }

        if (dist[p][last_price] + w * last_price != dist[cur][last_price]) {
            for (int i = 1; i < C; i++) {
                if (dist[p][i] + w * i == dist[cur][last_price]) {
                    last_price = i;
                    break;
                }
            }
        }

        cur = p;
    }

    reverse(path.begin(), path.end());

    vector<int> cnt(n);
    int cur_min = 0;

    for (int i = 0; i + 1 < path.size(); i++) {
        if (c[cur_min] > c[path[i]]) {
            cur_min = path[i];
        }
        int w = 0;
        for (auto [u, f] : g[path[i]]) {
            if (u == path[i + 1]) {
                w = f;
                break;
            }
        }
        cnt[cur_min] += w;
    }

    cout << path.size() << "\n";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] + 1 << " " << cnt[i] << "\n";
    }
}