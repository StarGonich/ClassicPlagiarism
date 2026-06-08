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

void next(vector<vector<int>>& a, vector<vector<int>>&b) {
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                if (i + 1 < n && a[i + 1][j] == 1) cnt ++;
                if (i - 1 >= 0 && a[i - 1][j] == 1) cnt ++;
                if (j + 1 < m && a[i][j + 1] == 1) cnt ++;
                if (j - 1 >= 0 && a[i][j - 1] == 1) cnt ++;
                if (i + 1 < n && j + 1 < m && a[i + 1][j + 1] == 1) cnt ++;
                if (i - 1 >= 0 && j + 1 < m && a[i - 1][j + 1] == 1) cnt ++;
                if (i + 1 < n && j - 1 >= 0 && a[i + 1][j - 1] == 1) cnt ++;
                if (i - 1 >= 0 && j - 1 >= 0 && a[i - 1][j - 1] == 1) cnt ++;
                if (a[i][j] == 1) b[i][j] = (cnt == 2 || cnt == 3);
                else b[i][j] = (cnt == 3);
            }
        }
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
        next(a[q], b[q]);
    }
    vector<int> prev(k, -1);
    for (int cur = 0; cur < k; cur++) {
        for (int i = 0; i < k; i++) {
            if (eq(a[cur], b[i])) {
                prev[cur] = i;
                break;
            }
        }
    }
    int start = -1;
    for (int i = 0; i < k; i++) {
        if (prev[i] == -1) start = i;
    }
    int cur = start;
    for (int i = 0; i < k; i++) {
        cout << cur + 1 << ' ';
        for (int j = 0; j < k; j++) {
            if (prev[j] == cur) {
                cur = j;
                break;
            }
        }
    }
    return 0;
}
