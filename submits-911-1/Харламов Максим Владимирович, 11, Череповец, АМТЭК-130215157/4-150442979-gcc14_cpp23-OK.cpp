#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    if (k >= n) {
        cout << 2 * n << endl;
        return 0;
    }
    int mindiv = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            mindiv = i;
            break;
        }
    }
    int q = n / mindiv * (mindiv + 1);
    if (q > n + k) cout << n + 1 << endl;
    else cout << q << endl;
    return 0;
}
