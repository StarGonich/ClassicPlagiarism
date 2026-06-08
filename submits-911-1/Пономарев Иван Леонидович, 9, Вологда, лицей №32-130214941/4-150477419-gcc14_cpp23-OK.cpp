#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a, b;
    cin >> a >> b;
    if (a <= 100000 && b <= 100000) {
        long long ans = 0, res = 1e18;
        for (int i = a + 1; i <= a + b; ++i) {
            if (a * i / gcd(a, i) < res) {
                res = a * i / gcd(a, i);
                ans = i;
            }
        }
        cout << ans;
        return 0;
    }
    for (long long i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            if (a + a / i <= a + b && a + a / i >= a + 1) {
                cout << a + a / i;
                return 0;
            }
        }
    }
}
