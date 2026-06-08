#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        live += config[ni][nj];
                    }
                }
            }
            if (config[i][j] == 1) {
                new_config[i][j] = (live == 2 || live == 3) ? 1 : 0;
            } else {
                new_config[i][j] = (live == 3) ? 1 : 0;
            }
        }
    }
    return new_config;
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
        
        for (int step = 0; step < 2000; step++) {
            auto next_config = next_state(current, n, m);
            
            bool found = false;
            for (int j = 0; j < k; j++) {
                if (j != i && next_config == configs[j]) {
                    graph[i].push_back(j);
                    indegree[j]++;
                    found = true;
                }
            }
            
            if (current == next_config) break;
            current = next_config;
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