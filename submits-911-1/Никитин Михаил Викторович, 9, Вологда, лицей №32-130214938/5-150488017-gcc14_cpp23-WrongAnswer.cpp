#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<pair<int, int> > v(k);
    for (int num = 0; num < k; num++) {
            int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a;
                cin >> a;
                sum += a;
            }
        }
        v.push_back({sum, num + 1});
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < k; i++) {
        cout << v[i].second << " ";
    }
    return 0;
}
