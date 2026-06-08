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
    long long ans = 0, res = 1e18;
    for (long long i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            if (a + a / i <= a + b && a + a / i >= a + 1) {
                if (a * (a + a / i) / gcd(a, a + a / i) < res) {
                    res = a * (a + a / i) / gcd(a, a + a / i);
                    ans = a + a / i;
                }
            }
        }
    }
    cout << ans;
}
