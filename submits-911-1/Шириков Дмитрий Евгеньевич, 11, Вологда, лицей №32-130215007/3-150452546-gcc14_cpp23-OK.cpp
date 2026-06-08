#include <bits/stdc++.h>
using namespace std;
signed main() {
    long long n, t;
    cin >> n >> t;
    vector<pair<long long, long long>> v;
    v.emplace_back(0, 0);
    for (long long i = 0; i < n; i++) {
        pair<long long, long long> p;
        cin >> p.first >> p.second;
        v.emplace_back(p);
    }
    n += 1;
    for (long long i = 0; i < n - 1; i++) {
        long long left = v[i].second - 1, right = v[i + 1].first;
        while (left + 1 < right) {
            long long mid = (left + right) / 2;
            long long len = 0;
            for (long long j = i + 1; j < n; j++) {
                if (mid + 3600 < v[j].first) break;
                if (mid + 3600 >= v[j].second) {
                    len += v[j].second - v[j].first;
                    continue;
                }
                len += mid + 3600 - v[j].first;
                break;
            }
            if (len > t) right = mid;
            else left = mid;
        }
        long long len = 0;
        for (long long j = i + 1; j < n; j++) {
            if (right + 3600 < v[j].first) break;
            if (right + 3600 >= v[j].second) {
                len += v[j].second - v[j].first;
                continue;
            }
            len += right + 3600 - v[j].first;
            break;
        }
        if (len > t) {
            cout << right;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
