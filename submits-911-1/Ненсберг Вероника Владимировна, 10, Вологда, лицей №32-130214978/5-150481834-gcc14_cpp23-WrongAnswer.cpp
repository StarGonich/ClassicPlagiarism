#include <bits/stdc++.h>

using namespace std;
int n, m;
map<string, int> st;

string s(vector<vector<int>> &a) {
    string ans;
    for (int i = 0; i <n; i++) {
        for (int j = 0; j < m; j++) {
            ans += char(a[i][j] + '0');
        }
    }
    return ans;
}

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
    if (st.find(s(a)) != st.end()) {
        return st[s(a)];
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
        st[s(g[cnt])] = cnt + 1;
    }
    vector<int> next(k, -1);
    int start = -1;
    for (int cnt = 0; cnt < k; cnt++) {
        next[cnt] = sad(g[cnt]) - 1;
    }
    vector<int> ans;
    while (ans.size() != n) {
        bool f = 0;
        for (int cnt = 0; cnt < k; cnt++) {
            if (next[cnt] == start) {
                ans.push_back(cnt);
                f = 1;
                if (start == cnt) {
                    f = 0;
                }
                start = cnt;
                break;
            }
        }
        if (!f) {
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto u : ans) {
        cout << u + 1 << " ";
    }
    return 0;
}
