#include <bits/stdc++.h>

using namespace std;

struct event {
    long long l, r;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long t;
    cin >> n >> t;
    vector<event> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
    }
    vector<int> p(n + 1);
    p[0] = 0;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + a[i - 1].r - a[i - 1].l;
    }
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        int j = i;
        while (j < n && a[j].r - a[i].r < 3600) j++;
        j--;
        if (p[j] - p[i] + a[i].l + 3599 - a[j].l > t) {
            int ans = a[i].l;
            int sdv = 0;
            for (int k = 0; k <= a[i].l + 3599 - a[j].l; ++k) {
                if (p[j] - p[i] + a[i].l + 3599 - a[j].l - k > t) {
                    sdv++;
                }
            }
            cout << ans - sdv;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
