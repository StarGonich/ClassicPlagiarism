#include <bits/stdc++.h>

#define fi first
#define se second
#define all(x) x.begin(), x.end()

#define int ll

using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

int query(int x) {
    assert(x > 0);

    cout << x << " R" << endl;
    int s; cin >> s;
    return s;
}

void solve() {
    int s = 210;
    int q = 0;
    int cnt = 0;

    while (true) {
        q++;
        assert(q <= 100);

        int x = s / 21;
        if (cnt == 1) x *= 3;
        else if (cnt == 2) x *= 6;
        else if (cnt == 3) x = s;

        int res = query(x);
        if (res == -1) {
            assert(false);
            break;
        }

        if (res == 0) {
            cnt++;
            s -= x;
        }
        else if (res == 1) {
            cnt = 0;
            s += x;
        }

        assert(s > 0);

        if (s >= 1000)
            break;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t --> 0) {
        solve();
    }

    return 0;
}
