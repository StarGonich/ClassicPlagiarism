#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int MOD = 1000000007;


void do_stuff() {
    int n, i, j, g, k;

    cin >> n;
    vi x(n), d(n);
    for(i = 0; i < n; i++) {
        cin >> x[i];
    }
    for(i = 0; i < n; i++) {
        cin >> d[i];
    }
    cin >> k;

    k--;
    int ans = 1;

    int l = x[k] - d[k], r = x[k] + d[k], li = k, ri = k;
    bool has = false;
    do {
        has = false;
        while((li > 0) and (x[li - 1] >= l)) {
            li--;
            l = min(l, x[li] - d[li]);
            r = max(r, x[li] + d[li]);
            has = true;
            ans++;
        }
        while((ri < n - 1) and (x[ri + 1] <= r)) {
            ri++;
            l = min(l, x[ri] - d[ri]);
            r = max(r, x[ri] + d[ri]);
            has = true;
            ans++;
        }
    } while(has);

    cout << ans << endl;
}

signed main() {
    int t = 1;

    //cin >> t;
    while(t--) {
        do_stuff();
    }
}