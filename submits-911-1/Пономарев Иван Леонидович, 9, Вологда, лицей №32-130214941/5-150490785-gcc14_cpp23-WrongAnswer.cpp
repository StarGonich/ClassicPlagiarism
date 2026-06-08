#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, n, m;
    cin >> k >> n >> m;
    vector<pair<int , int> > b(k);
    vector<vector<vector<int> > > a(k, vector<vector<int> > (n + 2, vector<int> (m + 2, -1)));
    for (int i = 0; i < k; ++i) {
        int sum = 0;
        for (int j = 1; j <= n; ++j) {
            for (int h = 1; h <= m; ++h) {
                cin >> a[i][j][h];
                sum += a[i][j][h];
            }
        }
        b[i].first = sum;
        b[i].second = i;
    }
    for (int i = 0; i < k; ++i) {
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
                    if (cnt < 2 || cnt > 3) b[i].first--;
                } else {
                    if (a[i][j - 1][h] == 1) cnt++;
                    if (a[i][j + 1][h] == 1) cnt++;
                    if (a[i][j][h - 1] == 1) cnt++;
                    if (a[i][j][h + 1] == 1) cnt++;
                    if (a[i][j - 1][h - 1] == 1) cnt++;
                    if (a[i][j + 1][h - 1] == 1) cnt++;
                    if (a[i][j - 1][h + 1] == 1) cnt++;
                    if (a[i][j + 1][h + 1] == 1) cnt++;
                    if (cnt == 3) b[i].first++;
                }
            }
        }
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < k; ++i) {
        cout << b[i].second + 1 << " ";
    }
    return 0;
}

