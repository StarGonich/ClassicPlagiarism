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
    map<vector<vector<int>>, int> num;
    for (int i = 0; i < k; ++i) {
            vector<vector<int>> v(n, vector<int> (m));
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < m; ++l) {
                cin >> v[j][l];
            }
        }
        num[v] = i;
    }
    vector<pair<int, int>> res;
    vector<int> result(k, -1);

    for (auto [v, ind] : num) {
        auto a = v;
        vector<vector<int>> cur(n, vector<int>(m));
        queue<pair<int, int>> q;
        int val = 0;
        while (true) {
            bool flag = false;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int sum = 0;
                    for (int c = 0; c < 8; ++c) {
                        int ni = i + di[c], nj = j + dj[c];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            sum += a[ni][nj];
                        }
                    }
                    if (sum == 3 && a[i][j] == 0) {
                        flag = true;
                        cur[i][j] = 1;
                        continue;
                    }
                    if (a[i][j] == 1 && (sum != 2 && sum != 3)) {
                        flag = true;
                        cur[i][j] = 0;
                        continue;
                    }
                    cur[i][j] = a[i][j];
                }
            }
            if (num.find(cur) != num.end() && result[num[cur]] != -1) {
                val += result[num[cur]];
                break;
            }
            if (num.find(cur) != num.end() && flag) {
                q.push({val, num[cur]});
            }
            if (flag) {
                val++;
                swap(a, cur);
            } else {
                break;
            }
        }
        res.push_back({val, ind});
        result[ind] = val;
        while (!q.empty()) {
            auto [b, c] = q.front();
            q.pop();
            res.push_back({val - b, c});
            result[c] = val - b;
        }
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

