#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e9;

int di[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dj[] = {-1, 0, 1, 1, 1, 0, -1, -1};


void solve() {
    int k;
    cin >> k;
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> num(k, vector<vector<int>>(n, vector<int>(m)));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < m; ++l) {
                cin >> num[i][j][k];
            }
        }
    }
    vector<pair<int, int>> res;
    for (int l = 0; l < k; ++l) {
        auto& v = num[l];
        vector<vector<int>> cur(n, vector<int>(m));
        int val = 0;
        while (true) {
            for (int i = 0; i < n; ++i) {
                int sum = 0;
                for (int j = 0; j < m; ++j) {
                    for (int c = 0; c < 8; ++c) {
                        int ni = i + di[c], nj = j + dj[c];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            sum += v[ni][nj];
                        }
                    }
                    if (sum == 3 && v[i][j] == 0) {
                        cur[i][j] = 1;
                        continue;
                    }
                    if (v[i][j] == 1 && (sum != 2 && sum != 3)) {
                        cur[i][j] = 0;
                        continue;
                    }
                    cur[i][j] = v[i][j];
                }
            }
            if (v != cur) {
                val++;
            } else {
                break;
            }
        }
        res.push_back({val, l});
    }
    sort(res.begin(), res.end());
    for (auto [a, b] : res) {
        cout << b + 1 << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}

