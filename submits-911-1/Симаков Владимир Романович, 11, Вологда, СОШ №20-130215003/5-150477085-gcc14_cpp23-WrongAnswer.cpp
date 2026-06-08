#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;
using Grid = vector<int>;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void read_config(int n, int m, Grid& config) {
    config.resize(n * m);
    for (int i = 0; i < n * m; i++) {
        cin >> config[i];
    }
}

void next_state(const Grid& config, Grid& next, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int live = 0;
            int current_idx = i * m + j;

            for (int d = 0; d < 8; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    live += config[ni * m + nj];
                }
            }

            if (config[current_idx] == 1) {
                next[current_idx] = (live == 2 || live == 3) ? 1 : 0;
            } else {
                next[current_idx] = (live == 3) ? 1 : 0;
            }
        }
    }
}
bool compare_grids(const Grid& a, const Grid& b) {
    return a == b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n, m;
    cin >> k >> n >> m;

    vector<Grid> configs(k);
    for (int idx = 0; idx < k; idx++) {
        read_config(n, m, configs[idx]);
    }

    vector<vector<bool>> reachable(k, vector<bool>(k, false));
    Grid current(n * m);
    Grid next(n * m);
    
    for (int i = 0; i < k; i++) {
        current = configs[i];
        bool stable = false;
        
        for (int step = 0; step < 2000 && !stable; step++) {
            next_state(current, next, n, m);
            stable = compare_grids(current, next);
            
            for (int j = 0; j < k; j++) {
                if (!reachable[i][j]) {
                    if (compare_grids(next, configs[j])) {
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
