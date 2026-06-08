#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    if (k >= n) cout << 2 * n << endl;
    else {
        int ans = n + 1;
        int nod = n / __gcd(n, n + 1) * (n + 1);
        for (int i = n + 1; i <= n + k; i++) {
            int q = n / __gcd(n, i) * i;
            if (q < nod) {
                ans = i;
                nod = q;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
