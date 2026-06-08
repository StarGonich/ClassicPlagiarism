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

void next_state(const vector<vector<int>>& config, vector<vector<int>>& next, int n, int m) {
    static const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int live = 0;
            for (int d = 0; d < 8; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    live += config[ni][nj];
                }
            }
            if (config[i][j] == 1) {
                next[i][j] = (live == 2 || live == 3) ? 1 : 0;
            } else {
                next[i][j] = (live == 3) ? 1 : 0;
            }
        }
    }
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

    vector<vector<bool>> reachable(k, vector<bool>(k, false));
    vector<vector<int>> current(n, vector<int>(m));
    vector<vector<int>> next(n, vector<int>(m));
    
    for (int i = 0; i < k; i++) {
        current = configs[i];
        bool stable = false;
        
        for (int step = 0; step < 2000 && !stable; step++) {
            next_state(current, next, n, m);
            
            stable = true;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (current[x][y] != next[x][y]) {
                        stable = false;
                        break;
                    }
                }
                if (!stable) break;
            }
            
            for (int j = 0; j < k; j++) {
                if (j != i && !reachable[i][j]) {
                    bool match = true;
                    for (int x = 0; x < n && match; x++) {
                        for (int y = 0; y < m && match; y++) {
                            if (next[x][y] != configs[j][x][y]) {
                                match = false;
                            }
                        }
                    }
                    if (match) {
                        reachable[i][j] = true;
                    }
                }
            }
            
            swap(current, next);
        }
    }

    vector<int> indegree(k, 0);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (reachable[i][j]) {
                indegree[j]++;
            }
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
        for (int j = 0; j < k; j++) {
            if (reachable[node][j]) {
                if (--indegree[j] == 0) {
                    q.push(j);
                }
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