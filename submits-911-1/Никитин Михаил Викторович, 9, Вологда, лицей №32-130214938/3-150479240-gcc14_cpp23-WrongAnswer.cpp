#include <bits/stdc++.h>
using namespace std;
const int INT  = 2000000000;
int main() {
    int n, t;
    cin >> n >> t;
    vector<array<int, 2>> v(n);
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + v[i - 1][1] - v[i - 1][0];
    }
    v.push_back({INT, INT});
    for (int i = 0; i < n; i++) {
        array<int, 2> b = {v[i][0] + 3600, -1};
        auto it = lower_bound(v.begin(), v.end(), b);
        int ind = it - v.begin();
        int res = pre[ind] - pre[i];
        res += max(0, v[i][0] + 3600 - v[ind][0]);
        if (res > t) {
            cout << v[i][0] - (res - t);
            return 0;
        }
    }
    cout << -1;
    return 0;
}
