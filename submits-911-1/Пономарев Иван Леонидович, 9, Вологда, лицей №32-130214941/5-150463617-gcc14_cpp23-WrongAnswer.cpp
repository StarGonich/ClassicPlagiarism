#include <bits/stdc++.h>

using namespace std;

struct event {
    long long l, r;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, n, m;
    cin >> k >> n >> m;
    vector<pair<int, int> > sum(k);
    for (int i = 0; i < k; ++i) {
        int res = 0;
        for (int j = 0; j < n; ++j) {
            for (int h = 0; h < m; ++h) {
                int x;
                cin >> x;
                res += x;
            }
        }
        sum[i].first = res;
        sum[i].second = i + 1;
    }
    sort(sum.rbegin(), sum.rend());
    for (int i = 0; i < k; ++i) {
        cout << sum[i].second << " ";
    }
    return 0;
}
