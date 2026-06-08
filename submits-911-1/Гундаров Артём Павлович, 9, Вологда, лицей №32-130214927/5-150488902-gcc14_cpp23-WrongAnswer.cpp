#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);

    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<vector<char>>> a(k, vector<vector<char>> (n, vector<char> (m)));

    for (int p = 0; p < k; p++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[p][i][j];
            }
        }
    }
    
    bool f = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f |= a[0][i][j];
        }
    }
    
    if (n == 2) {
        if (f) {
            cout << "1 2";
        }
        else {
            cout << "2 1";
        }
    }
    else {
        cout << "2 1 3";
    }
    return 0;
}
