#include <bits/stdc++.h>
using namespace std;

bool is_good(int h, int m) {
    bool b = 0;
    if (h == m) {
        b = 1;
    }
    if (h == 1 && m == 23) {
        b = 1;
    }
    if (h == 12 && m == 34) {
        b = 1;
    }
    if (h == 23 && m == 45) {
        b = 1;
    }
    h = 10 * (h % 10) + h / 10;
    if (h == m) {
        b = 1;
    }
    return b;
}

int main() {
	int h1, h2, m1, m2;
	cin >> h1 >> m1 >> h2 >> m2;
    int ans = 0;
    if (h1 * 60 + m1 > h2 * 60 + m2) {
        h2 += 24;
    }
    for (int i = h1 * 60 + m1; i <= h2 * 60 + m2; i++) {
        i %= 24 * 60;
        int h = i / 60, m = i % 60;
        if (is_good(h, m)) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
