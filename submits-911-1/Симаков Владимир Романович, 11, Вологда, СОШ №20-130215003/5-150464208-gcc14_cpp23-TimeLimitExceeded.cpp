#include <iostream>
#include <vector>
#include <tuple>
#include <set>
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
            int live_neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        live_neighbors += config[ni][nj];
                    }
                }
            }
            if (config[i][j] == 1) {
                if (live_neighbors == 2 || live_neighbors == 3) {
                    new_config[i][j] = 1;
                } else {
                    new_config[i][j] = 0;
                }
            } else {
                if (live_neighbors == 3) {
                    new_config[i][j] = 1;
                } else {
                    new_config[i][j] = 0;
                }
            }
        }
    }
    return new_config;
}

using ConfigTuple = vector<vector<int>>;

ConfigTuple config_to_tuple(const vector<vector<int>>& config) {
    return config;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n, m;
    cin >> k >> n >> m;

    vector<vector<vector<int>>> configs(k);
    vector<ConfigTuple> config_tuples(k);

    for (int idx = 0; idx < k; idx++) {
        configs[idx] = read_config(n, m);
        config_tuples[idx] = config_to_tuple(configs[idx]);
    }

    vector<vector<int>> graph(k);
    vector<int> indegree(k, 0);

    for (int i = 0; i < k; i++) {
        auto current = configs[i];
        set<ConfigTuple> visited_states;
        visited_states.insert(config_tuples[i]);

        int step = 0;
        while (step < 2000) {
            current = next_state(current, n, m);
            ConfigTuple current_tuple = config_to_tuple(current);
            if (visited_states.count(current_tuple)) {
                break;
            }
            visited_states.insert(current_tuple);
            for (int j = 0; j < k; j++) {
                if (j != i && current_tuple == config_tuples[j]) {
                    graph[i].push_back(j);
                    indegree[j]++;
                }
            }
            step++;
        }
    }

    queue<int> q;
    for (int i = 0; i < k; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node + 1);
        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
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