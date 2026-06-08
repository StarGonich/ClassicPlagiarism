#include <iostream>
#include <vector>
#include <set>
using namespace std;

pair<vector<int>, vector<int>> dijkstra(vector<vector<pair<int, int>>>& g, int from) {
    int n = g.size();
    vector<int> d(n, -1);
    vector<int> f(n, -1);
    vector<bool> check(n, false);
    set<pair<int, pair<int, int>>> q;
    q.insert({0, {from, -1}});
    while (!q.empty()) {
        int from = (*q.begin()).second.first;
        int dist = (*q.begin()).first;
        int prev = (*q.begin()).second.second;
        q.erase(q.begin());
        if (check[from]) continue;
        check[from] = true;
        d[from] = dist;
        f[from] = prev;
        for (auto [k, v] : g[from]) {
            if (!check[k]) {
                q.insert({dist + v, {k, from}});
            }
        }
    }
    return {d, f};
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<vector<pair<int, int>>> g(n);
    int x, y, z;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> z;
        --x; --y;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    vector<vector<int>> r;
    vector<vector<int>> p;
    for (int i = 0; i < n; ++i) {
        auto dijk = dijkstra(g, i);
        r.push_back(dijk.first);
        p.push_back(dijk.second);
        for (int j = 0; j < n; ++j) r[i][j] *= c[i];
    }
    auto r0 = r;
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << r[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << p[i][j]+1 << " ";
        }
        cout << "\n";
    }*/
    if (r[0][n-1] <= 0) {
        cout << "-1";
        return 0;
    }
    vector<vector<int>> prev;
    for (int i = 0; i < n; ++i) {
        prev.push_back(vector<int>(n, i));
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (r[i][j] > r[i][k] + r[k][j]) {
                    // идем через k
                    r[i][j] = r[i][k] + r[k][j];
                    prev[i][j] = k;
                }
            }
        }
    }

    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << r[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << prev[i][j] + 1 << " ";
        }
        cout << "\n";
    } */

    int sum = 0;
    vector<pair<int, int>> path;
    int pos = n-1;
    path.push_back({pos + 1, 0});
    int next = -1;
    while (pos != 0) {
        int prevpos = pos;
        next = prev[0][pos];
        pos = p[next][pos];
        while (pos != next) {
            path.push_back({pos + 1, 0});
            pos = p[next][pos];
        }
        path.push_back({pos + 1, r0[pos][prevpos] / c[pos]});
        sum += r0[pos][prevpos];
        //cout << " " << r0[pos][prevpos] << "\n";
    }

    cout << sum << "\n" << path.size() << "\n";
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i].first << " " << path[i].second << "\n";
    }
}
