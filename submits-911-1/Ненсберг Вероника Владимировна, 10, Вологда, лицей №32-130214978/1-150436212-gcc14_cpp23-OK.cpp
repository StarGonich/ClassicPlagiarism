#include <bits/stdc++.h>

using namespace std;

int main() {
    int h1, h2, m1, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int ans = 0;
    if (h1 == m1 || (h1 % 10) * 10 + (h1 / 10) == m1 || ((h1 / 10) + 1 == h1 % 10 && h1 % 10 + 1 == (m1 / 10) && (m1 / 10) + 1 == m1 % 10)) {
        ans++;
    }
    while (h1 != h2 || m1 != m2) {
        m1++;
        if (m1 == 60) {
            h1++;
            if (h1 == 24) {
                h1 = 0;
            }
            m1 = 0;
        }
        if (h1 == m1 || (h1 % 10) * 10 + (h1 / 10) == m1 || ((h1 / 10) + 1 == h1 % 10 && h1 % 10 + 1 == (m1 / 10) && (m1 / 10) + 1 == m1 % 10)) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
