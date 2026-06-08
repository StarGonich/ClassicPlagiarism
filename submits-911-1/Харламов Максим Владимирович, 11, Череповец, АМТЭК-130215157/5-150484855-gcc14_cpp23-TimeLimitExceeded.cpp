#include<bits/stdc++.h>
using namespace std;

int eq(vector<vector<int>>& a, vector<vector<int>>&b) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] != b[i][j]) return 0;
        }
    }
    return 1;
}

void next(vector<vector<int>>& a, vector<vector<int>>&b) {
    int n = a.size();
    int m = a[0].size();
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
const int MAX = 2025;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    int n, m;
    cin >> n >> m;
    vector<int> len(k, -1);
    vector<vector<vector<int>>> a(k, vector<vector<int>>(n, vector<int>(m, 0)));
    vector<vector<int>> dp[MAX];
    vector<vector<int>> minusone(n, vector<int>(m, -1));
    fill(dp, dp + MAX, minusone);
    int first = MAX - 1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int q = 0; q < m; q++) {
                cin >> a[i][j][q];
            }
        }
        int ans = 0;
        int first = 0;
        for (int j = 0; j < MAX; j++) {
            if (eq(dp[j], a[i])) {
                len[i] = j;
                ans = 1;
            }
        }
        auto w = minusone;
        auto cur = a[i];
        int cnt = 0;
        vector<vector<vector<int>>> curdp(1, cur);
        while (!eq(cur, dp[first]) && !(eq(cur, w))) {
            next(cur, w);
            swap(cur, w);
            curdp.push_back(cur);
        }
        if (eq(cur, w)) {
            first = MAX - curdp.size();
            for (int j = MAX - curdp.size(); j < MAX; j++) {
                dp[j] = curdp[j - MAX + curdp.size()];
            }
        }
        else {
            for (int j = first - curdp.size(); j < first; j++) {
                dp[j] = curdp[j - first + curdp.size()];
            }
            first = first - curdp.size();
        }
        len[i] = MAX - first;
    }
    vector<int> ind(k);
    for (int i = 0; i < k; i++) ind[i] = i;
    sort(ind.begin(), ind.end(), [&](int a, int b) {
         return len[a] > len[b];
    });
    for (int i: ind) cout << i + 1 << '\n';
    return 0;
}
