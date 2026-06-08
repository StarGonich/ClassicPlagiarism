#include <bits/stdc++.h>

using namespace std;
int n, m;
map<vector<vector<int>>, int> st;
int sad(vector<vector<int>> &a) {
    vector<vector<int>> b(n, vector<int> (m, 0));
    for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
        int cnt = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) {
                    continue;
                }
                if (x + dx < 0 || x + dx == n || y + dy < 0 || y + dy == n) {
                    continue;
                }
                cnt += a[x + dx][y + dy];
            }
        }
        if (cnt == 3 && a[x][y] == 0) {
            b[x][y] = 1;
            continue;
        }
        if (cnt >= 2 && cnt <= 3 && a[x][y] == 1) {
            b[x][y] = 1;
            continue;
        }
    }
    }
    bool f = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (a[x][y] != b[x][y]) {
                f = 1;
            }
            a[x][y] = b[x][y];
        }
    }
    if (!f) {
        return 0;
    }
    if (st.find(a) != st.end()) {
        return st[a];
    }
    if (f) {
        return sad(a);
    }
    return 0;
}

int main() {
    int k;
    cin >> k >> n >> m;
    vector<vector<vector<int>>> g(k, vector<vector<int>> (n, vector<int> (m, 0)));
    for (int cnt = 0; cnt < k; cnt++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[cnt][i][j];
            }
        }
        st[g[cnt]] = cnt + 1;
    }
    vector<int> next(k, -1);
    int st = -1;
    for (int cnt = 0; cnt < k; cnt++) {
        next[cnt] = sad(g[cnt]) - 1;
    }
    vector<int> ans;
    while (1) {
        bool f = 0;
        for (int cnt = 0; cnt < k; cnt++) {
            if (next[cnt] == st) {
                ans.push_back(cnt);
                st = cnt;
                f = 1;
                break;
            }
        }
        if (!f) {
            break;
        }
    }
    for (auto u : ans) {
        cout << u + 1 << " ";
    }
    for (auto u : next) {
        cout << u + 1 << " ";
    }
    return 0;
}
