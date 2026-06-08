#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (!a) return b;
    if (!b) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int ans = n / 4 + n / 5 + n / 6;

    ans -= n / lcm(4, 5) * 2;
    ans -= n / lcm(4, 6) * 2;
    ans -= n / lcm(5, 6) * 2;
    ans += n / lcm(4, lcm(5, 6)) * 6;

    cout << ans << '\n';
}
