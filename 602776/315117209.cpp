#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int ans = 0;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n;

    for (int i = 4; i <= n; i += 4) {
        if (i % 5 == 0 || i % 6 == 0)
            continue;
        ans += 1;
    }

    for (int i = 5; i <= n; i += 5) {
        if (i % 4 == 0 || i % 6 == 0)
            continue;
        ans += 1;
    }

    for (int i = 6; i <= n; i += 6) {
        if (i % 4 == 0 || i % 5 == 0)
            continue;
        ans += 1;
    }

    cout << ans;
}