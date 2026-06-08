#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    if (2 * n <= n + k) {
        cout << 2 * n;
        return 0;
    }
    long long ans = 2 * n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        if (n * (i + 1) / i <= n + k) {
            cout << n * (i + 1) / i;
            return 0;
        }
        long long d = n / i;
        if (n * (d + 1) / d <= n + k) {
            ans = d;
        }
    }
    if (ans == 2 * n) {
        cout << n + 1;
        return 0;
    }
    cout << ans;
    return 0;
}
