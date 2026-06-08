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
using vpi = vector<pii>;

void solve() {
    int n; cin >> n;

    if (n == 1) {
        cout << 1;
        return;
    }

    if (n == 2) {
        cout << "3 4 5";
        return;
    }

    if (n % 2 == 0) {
        int x = n / 2;
        for (int i = 0; i < n-1; i++)
            cout << 1 << ' ';
        cout << x-1 << ' ' << x;
        return;
    }

    n += 7;
    int x = n / 2;
    for (int i = 0; i < n-1-9; i++)
        cout << 1 << ' ';
    cout << 3 << ' ' << x-1 << ' ' << x;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t --> 0) {
        solve();
        cout << '\n';
    }

    return 0;
}
