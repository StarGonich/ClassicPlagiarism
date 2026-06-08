#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int k, n, m;
vector<vector<int>> res;
vector<vector<int>> next_table(vector<vector<int>>& cur) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cnt = 0;
            for (int shift_x = -1; shift_x <= 1; shift_x++) {
                for (int shift_y = -1; shift_y <= 1; shift_y++) {
                    if (shift_x == 0 && shift_y == 0) continue;
                    cnt += cur[i + shift_x][j + shift_y];
                }
            }
            if (cur[i][j] == 1) {
                if (cnt == 2 || cnt == 3) res[i][j] = 1;
                else res[i][j] = 0;
            }
            if (cur[i][j] == 0) {
                if (cnt == 3) res[i][j] = 1;
                else res[i][j] = 0;
            }
        }
    }
    return res;
}
signed main() {
    cin >> k >> n >> m;
    res.resize(n + 2, vector<int> (m + 2));
    vector<vector<vector<int>>> v(k, vector<vector<int>> (n + 2, vector<int> (m + 2)));
    map<vector<vector<int>>, int> mp;
    for (int a = 0; a < k; a++) {
        for (int b = 1; b <= n; b++) {
            for (int c = 1; c <= m; c++) {
                cin >> v[a][b][c];
            }
        }
        mp[v[a]] = a;
    }
    cout << "\n";
    for (int start = 0; start < k; start++) {
        map<int, int> used;
        vector<vector<int>> cur = v[start];
        used[start] = 1;
        vector<int> ans = {start};
        int cnt = 0;
        while (true) {
            vector<vector<int>> nxt = next_table(cur);
            if (!used[mp[nxt]]) ans.emplace_back(mp[nxt]);
            used[mp[nxt]] = 1;
            cur = nxt;
            cnt++;
            if (cnt >= 600) break;
        }
        if (ans.size() == k) {
            for (auto el : ans) cout << el + 1 << " ";
            return 0;
        }
    }
    return 0;
}
