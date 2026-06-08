#include<bits/stdc++.h>

using namespace std;
#define int long long

int eq(vector<vector<int>>& a, vector<vector<int>>&b) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] != b[i][j]) return 0;
        }
    }
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> a(k, vector<vector<int>>(n, vector<int>(m)));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int q = 0; q < m; q++) {
                cin >> a[i][j][q];
            }
        }
    }
    auto b = a;
    for (int q = 0; q < k; q++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                if (i + 1 < n && a[q][i + 1][j] == 1) cnt ++;
                if (i - 1 >= 0 && a[q][i - 1][j] == 1) cnt ++;
                if (j + 1 < m && a[q][i][j + 1] == 1) cnt ++;
                if (j - 1 >= 0 && a[q][i][j - 1] == 1) cnt ++;
                if (i + 1 < n && j + 1 < m && a[q][i + 1][j + 1] == 1) cnt ++;
                if (i - 1 >= 0 && j + 1 < m && a[q][i - 1][j + 1] == 1) cnt ++;
                if (i + 1 < n && j - 1 >= 0 && a[q][i + 1][j - 1] == 1) cnt ++;
                if (i - 1 >= 0 && j - 1 >= 0 && a[q][i - 1][j - 1] == 1) cnt ++;
                if (a[q][i][j] == 1) b[q][i][j] = (cnt == 2 || cnt == 3);
                else b[q][i][j] = (cnt == 3);
            }
        }
    }
    vector<int> res(k);
    vector<int> used(k, 0);
    for (int i = 0; i < k; i++) {
        if (eq(a[i], b[i])) {
            res[k - 1] = i;
            used[i] = 1;
            break;
        }
    }
    for (int cur = k - 2; cur >= 0; cur--) {
        for (int i = 0; i < k; i++) {
            if (!used[i] && eq(b[i], a[res[cur + 1]])) {
                res[cur] = i;
                used[i] = 1;
                break;
            }
        }
    }
    for (int i: res) cout << i + 1 << ' ';
    return 0;
}
