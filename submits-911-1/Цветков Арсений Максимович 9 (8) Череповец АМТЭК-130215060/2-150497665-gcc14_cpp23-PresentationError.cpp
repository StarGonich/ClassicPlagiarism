#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a,b);
    }
    return a;
}
int lcm(int a, int b) {
    return a / gcd(a,b) * b;
}

void solve(){
    long long n;
    cin >> n;
    if (n == 1) {
        cout << 1;
    } else if (n == 2) {
        cout << -1;
    } else if (n == 3) {
        cout << 6 << "\n" << 3 << " " << 2 << " " << 1;
    } else {
        long long x = 36 * pow(2, n -4);
        cout << x << endl;
        cout << 3 << " " << 6 << " " << 9 << " " << 18 << " ";
        for (long long i = 36; (long long) i < x; i *= 2) {
            cout << i << " ";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
