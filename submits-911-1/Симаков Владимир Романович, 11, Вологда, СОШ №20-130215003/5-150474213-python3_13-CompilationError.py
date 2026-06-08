#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n, m;
    cin >> k >> n >> m;

    vector<vector<vector<int>>> configs(k);
    vector<long long> hashes(k);
    
    for (int idx = 0; idx < k; idx++) {
        configs[idx] = vector<vector<int>>(n, vector<int>(m));
        long long hash = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> configs[idx][i][j];
                hash = hash * 131 + configs[idx][i][j];
            }
        }
        hashes[idx] = hash;
    }

    vector<int> order(k);
    for (int i = 0; i < k; i++) order[i] = i;

    sort(order.begin(), order.end(), [&](int a, int b) {
        int live_a = 0, live_b = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                live_a += configs[a][i][j];
                live_b += configs[b][i][j];
            }
        }
        return live_a < live_b;
    });

    vector<int> result(k);
    for (int i = 0; i < k; i++) {
        result[i] = order[i] + 1;
    }

    for (int i = 0; i < k; i++) {
        if (i > 0) cout << ' ';
        cout << result[i];
    }
    cout << '\n';

    return 0;
}