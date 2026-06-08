#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    for (int i = h1 * 60 + m1; i <= h2 * 60 + m2; i++) {
        int h = i / 60, m = i % 60;
        if (h == m) {
            ans++;
            continue;
        }
        if (h == 1 && m == 23) {
            ans++;
        }
        if (h == 12 && m == 34) {
            ans++;
        }
        if (h == 23 && m == 45) {
            ans++;
        }
        h = 10 * (h % 10) + h / 10;
        if (h == m) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
