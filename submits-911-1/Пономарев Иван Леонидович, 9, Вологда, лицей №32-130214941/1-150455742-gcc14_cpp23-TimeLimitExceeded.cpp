#include <bits/stdc++.h>

using namespace std;

struct event {
    long long l, r;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    set<pair<int, int> > s;
    s.insert({1, 23});
    s.insert({12, 34});
    s.insert({23, 45});
    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < 60; ++j) {
            if (i == j || (i / 10 == j % 10 && i % 10 == j / 10)) {
                s.insert({i, j});
            }
        }
    }
    long long ans = 0;
    while (h1 != h2 || m1 != m2) {
        if (s.find({h1, m1}) != s.end()) {
            ans++;
        }
        m1++;
        if (m1 == 60) {
            m1 = 0;
            h1++;
        }
    }
    cout << ans;
    return 0;
}
