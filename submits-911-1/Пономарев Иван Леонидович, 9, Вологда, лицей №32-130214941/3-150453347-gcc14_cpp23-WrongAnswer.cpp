#include <bits/stdc++.h>

using namespace std;

struct event {
    long long l, r;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long t;
    cin >> n >> t;
    vector<event> a(n);
    vector<int> raz (1000000 + 2);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
        raz[a[i].l]++;
        raz[a[i].r + 1]--;
    }
    vector<int> b(1000000 + 2);
    b[0] = raz[0];
    for (int i = 1; i < b.size(); ++i) {
        b[i] = b[i - 1] + raz[i];
    }
    vector<int> p(b.size());
    p[0] = 0;
    for (int i = 1; i < p.size(); ++i) {
        p[i] = p[i - 1] + b[i - 1];
    }
//    for (int i = 0; i <= 3600; ++i) {
//        cout << p[i] << '\n';
//    }
    for (int i = 3600; i < p.size(); ++i) {
        if (i > a.back().r) break;
        if (p[i] - p[i - 3600] > t) {
            cout << i - 3600 + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
