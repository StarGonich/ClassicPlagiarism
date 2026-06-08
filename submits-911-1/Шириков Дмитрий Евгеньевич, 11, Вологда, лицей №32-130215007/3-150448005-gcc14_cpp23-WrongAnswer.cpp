#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> v;
    v.emplace_back(-1, -1);
    for (int i = 0; i < n; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        v.emplace_back(p);
    }
    v.emplace_back(1e9 * 2, 1e9 * 2);
    n += 2;
    for (int i = 0; i < n - 1; i++) {
        int left = v[i].second - 1, right = v[i + 1].first;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            int len = 0;
            for (int j = i + 1; j < n; j++) {
                if (mid + 3600 < v[j].first) break;
                if (mid + 3600 >= v[j].second) {
                    len += v[j].second - v[j].first;
                    continue;
                }
                len += mid + 3600 - v[j].first;
                break;
            }
            if (len >= t) right = mid;
            else left = mid;
        }
        int len = 0;
        for (int j = i + 1; j < n; j++) {
            if (right + 3600 < v[j].first) break;
            if (right + 3600 >= v[j].second) {
                len += v[j].second - v[j].first;
                continue;
            }
            len += right + 3600 - v[j].first;
            break;
        }
        if (len >= t) {
            cout << right + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
