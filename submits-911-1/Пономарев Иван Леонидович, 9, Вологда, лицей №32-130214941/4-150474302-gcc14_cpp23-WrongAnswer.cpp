#include <bits/stdc++.h>

using namespace std;

struct event {
    long long l, r;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a, b;
    cin >> a >> b;
    for (int i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            if (a + a / i <= a + b && a + a / i >= a + 1) {
                cout << a + a/i;
                return 0;
            }
        }
    }
    return 0;
}
