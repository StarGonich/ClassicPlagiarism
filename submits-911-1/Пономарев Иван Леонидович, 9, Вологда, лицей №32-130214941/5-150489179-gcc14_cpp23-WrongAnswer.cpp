#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, n, m;
    cin >> k >> n >> m;
    map<vector<vector<int> >, int> mp;
    vector<vector<vector<int> > > a(k, vector<vector<int> > (n + 2, vector<int> (m + 2, -1)));
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int h = 1; h <= m; ++h) {
                cin >> a[i][j][h];
            }
        }
        mp[a[i]] = i;
    }
    vector<int> pre(k);
    for (int i = 0; i < k; ++i) {
        vector<vector<int> > b = a[i];
        for (int j = 1; j <= n; ++j) {
            for (int h = 1; h <= m; ++h) {
                int cnt = 0;
                if (a[i][j][h] == 1) {
                    if (a[i][j - 1][h] == 1) cnt++;
                    if (a[i][j + 1][h] == 1) cnt++;
                    if (a[i][j][h - 1] == 1) cnt++;
                    if (a[i][j][h + 1] == 1) cnt++;
                    if (a[i][j - 1][h - 1] == 1) cnt++;
                    if (a[i][j + 1][h - 1] == 1) cnt++;
                    if (a[i][j - 1][h + 1] == 1) cnt++;
                    if (a[i][j + 1][h + 1] == 1) cnt++;
                    if (cnt < 2 || cnt > 3) b[j][h] = 0;
                } else {
                    if (a[i][j - 1][h] == 1) cnt++;
                    if (a[i][j + 1][h] == 1) cnt++;
                    if (a[i][j][h - 1] == 1) cnt++;
                    if (a[i][j][h + 1] == 1) cnt++;
                    if (a[i][j - 1][h - 1] == 1) cnt++;
                    if (a[i][j + 1][h - 1] == 1) cnt++;
                    if (a[i][j - 1][h + 1] == 1) cnt++;
                    if (a[i][j + 1][h + 1] == 1) cnt++;
                    if (cnt == 3) b[j][h] = 1;
                }
            }
        }
        pre[i] = mp[b];
    }
    int st;
    for (int i = 0; i < k; ++i) {
        vector<bool> is(k);
        is[i] = 1;
        int s = i, ss = i;
        while (s != pre[s]) {
            s = pre[s];
            is[s] = 1;
        }
        bool f = 0;
        for (int i = 0; i < n; ++i) {
            if (is[i] == 0) {
                f = 1;
            }
        }
        if (!f) {
            st = ss;
            break;
        }
    }
    cout << st + 1 << " ";
    while (st != pre[st]) {
        st = pre[st];
        cout << st + 1 << " ";
    }
}
