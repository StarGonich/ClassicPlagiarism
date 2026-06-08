#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> read_config(int n, int m) {
    vector<vector<int>> config(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> config[i][j];
        }
    }
    return config;
}

vector<vector<int>> next_state(const vector<vector<int>>& config, int n, int m) {
    vector<vector<int>> new_config(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int live = 0;
            int imin = max(0, i-1), imax = min(n-1, i+1);
            int jmin = max(0, j-1), jmax = min(m-1, j+1);
            for (int ni = imin; ni <= imax; ni++) {
                for (int nj = jmin; nj <= jmax; nj++) {
                    if (ni == i && nj == j) continue;
                    live += config[ni][nj];
                }
            }
            if (config[i][j] == 1) {
                new_config[i][j] = (live == 2 || live == 3);
            } else {
                new_config[i][j] = (live == 3);
            }
        }
    }
    return new_config;
}

bool equal_configs(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n, m;
    cin >> k >> n >> m;

    vector<vector<vector<int>>> configs(k);
    for (int idx = 0; idx < k; idx++) {
        configs[idx] = read_config(n, m);
    }

    vector<vector<int>> graph(k);
    vector<int> indegree(k, 0);

    for (int i = 0; i < k; i++) {
        auto current = configs[i];
        auto prev = current;
        
        for (int step = 0; step < 2000; step++) {
            auto next = next_state(current, n, m);
            
            for (int j = 0; j < k; j++) {
                if (j != i && equal_configs(next, configs[j])) {
                    graph[i].push_back(j);
                    indegree[j]++;
                }
            }
            
            if (equal_configs(next, prev)) break;
            prev = current;
            current = next;
        }
    }

    queue<int> q;
    for (int i = 0; i < k; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node + 1);
        for (int neighbor : graph[node]) {
            if (--indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    for (size_t i = 0; i < result.size(); i++) {
        if (i > 0) cout << ' ';
        cout << result[i];
    }
    cout << '\n';

    return 0;
}