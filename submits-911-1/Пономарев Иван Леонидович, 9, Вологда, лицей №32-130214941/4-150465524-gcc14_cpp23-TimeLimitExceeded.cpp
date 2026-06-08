#include <bits/stdc++.h>

using namespace std;

struct event {
    long long l, r;
};

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
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    long long res = 1e10;
    for (int i = n + 1; i <= n + k; ++i) {
        if (n * i / gcd(n, i) < res) {
            ans = i;
            res = n * i / gcd(n, i);
        }
    }
    cout << ans;
    return 0;
}
