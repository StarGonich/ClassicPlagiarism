#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int k, n, m;
vector<vector<vector<short>>> configs;

void read_config(int idx) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> configs[idx][i][j];
        }
    }
}

inline void next_state(const vector<vector<short>>& config, vector<vector<short>>& next) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int live = 0;
            int imin = i > 0 ? i-1 : 0;
            int imax = i < n-1 ? i+1 : n-1;
            int jmin = j > 0 ? j-1 : 0;
            int jmax = j < m-1 ? j+1 : m-1;
            
            for (int ni = imin; ni <= imax; ni++) {
                for (int nj = jmin; nj <= jmax; nj++) {
                    if (ni == i && nj == j) continue;
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

inline bool compare_configs(const vector<vector<short>>& a, const vector<vector<short>>& b) {
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

    cin >> k >> n >> m;
    configs.resize(k, vector<vector<short>>(n, vector<short>(m)));
    
    for (int idx = 0; idx < k; idx++) {
        read_config(idx);
    }

    vector<vector<short>> graph(k);
    vector<short> indegree(k, 0);
    
    vector<vector<short>> current(n, vector<short>(m));
    vector<vector<short>> next(n, vector<short>(m));
    
    for (int i = 0; i < k; i++) {
        current = configs[i];
        
        for (int step = 0; step < 100; step++) {
            next_state(current, next);
            
            for (int j = 0; j < k; j++) {
                if (j != i && compare_configs(next, configs[j])) {
                    graph[i].push_back(j);
                    indegree[j]++;
                }
            }
            
            bool same = true;
            for (int x = 0; x < n && same; x++) {
                for (int y = 0; y < m && same; y++) {
                    if (current[x][y] != next[x][y]) same = false;
                }
            }
            if (same) break;
            swap(current, next);
        }
    }

    queue<short> q;
    for (int i = 0; i < k; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<short> result;
    while (!q.empty()) {
        short node = q.front();
        q.pop();
        result.push_back(node + 1);
        for (short neighbor : graph[node]) {
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