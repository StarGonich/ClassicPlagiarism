#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

int count_live(const vector<vector<int>>& config, int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count += config[i][j];
        }
    }
    return count;
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

    vector<int> order(k);
    for (int i = 0; i < k; i++) order[i] = i;

    sort(order.begin(), order.end(), [&](int a, int b) {
        return count_live(configs[a], n, m) < count_live(configs[b], n, m);
    });

    for (int i = 0; i < k; i++) {
        if (i > 0) cout << ' ';
        cout << order[i] + 1;
    }
    cout << '\n';

    return 0;
}