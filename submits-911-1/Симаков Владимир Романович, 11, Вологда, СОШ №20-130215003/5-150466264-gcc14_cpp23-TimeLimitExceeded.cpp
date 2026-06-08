#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct ConfigHash {
    size_t operator()(const vector<vector<int>>& config) const {
        size_t hash = 0;
        for (const auto& row : config) {
            for (int val : row) {
                hash = hash * 131 + val;
            }
        }
        return hash;
    }
};

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
    unordered_map<size_t, vector<int>> hash_to_indices;
    ConfigHash hasher;

    for (int idx = 0; idx < k; idx++) {
        configs[idx] = read_config(n, m);
        size_t h = hasher(configs[idx]);
        hash_to_indices[h].push_back(idx);
    }

    vector<vector<int>> graph(k);
    vector<int> indegree(k, 0);

    for (int i = 0; i < k; i++) {
        auto current = configs[i];
        unordered_map<size_t, bool> visited;
        size_t current_hash = hasher(current);
        visited[current_hash] = true;

        int step = 0;
        while (step < 2000) {
            auto next_config = next_state(current, n, m);
            size_t next_hash = hasher(next_config);
            
            if (visited.count(next_hash)) break;
            visited[next_hash] = true;
            
            auto it = hash_to_indices.find(next_hash);
            if (it != hash_to_indices.end()) {
                for (int j : it->second) {
                    if (j != i) {
                        graph[i].push_back(j);
                        indegree[j]++;
                    }
                }
            }
            
            current = next_config;
            step++;
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