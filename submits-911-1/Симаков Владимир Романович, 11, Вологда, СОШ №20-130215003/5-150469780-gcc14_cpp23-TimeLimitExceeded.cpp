#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

const int MAX_CELLS = 5000;

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
    
    for (int i = 0; i < k; i++) {
        vector<vector<int>> current = configs[i];
        vector<vector<int>> next(n, vector<int>(m));
        
        for (int step = 0; step < 2000; step++) {
            next_state(current, next, n, m);
            
            bool changed = false;
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
            
            bool same = true;
            for (int x = 0; x < n && same; x++) {
                for (int y = 0; y < m && same; y++) {
                    if (current[x][y] != next[x][y]) {
                        same = false;
                    }
                }
            }
            if (same) break;
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