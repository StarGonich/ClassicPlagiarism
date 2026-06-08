#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define S second
using namespace std;

struct point {
    int x, y, c;
};

signed main() {
    int n;
    cin >> n;
    vector<point> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].c;
    }

    vector<vector<pair<int, int>>> dist(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dist[i].pb({(a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y), a[j].c});
            dist[j].pb({(a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y), a[i].c});
        }
    }

    vector<vector<int>> pref(n);
    for (int i = 0; i < n; i++) {
        sort(all(dist[i]));
        int cnt = 0;
        for (int j = 0; j < n - 1; j++) {
            if (dist[i][j].S == 1) cnt += 1;
            else cnt -= 1;
            if (j % 2 == 0) {
                if (cnt > 0) {
                    pref[i].pb(1);
                }
                else {
                    pref[i].pb(0);
                }
            }
        }
    }

    for (int k = 0; k < n - 1; k++) {
        int ans = 0;
        if (k % 2 == 0) {
            for (int i = 0; i < n; i++) {
                if (pref[i][k / 2] == a[i].c) {
                    ans += 1;
                }
            }
            cout << ans << "\n";
        }
    }
}
