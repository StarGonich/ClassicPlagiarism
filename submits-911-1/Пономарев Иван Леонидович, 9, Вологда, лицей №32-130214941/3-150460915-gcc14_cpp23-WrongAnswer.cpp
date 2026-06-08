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
    vector<int> raz (1000002);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
        raz[a[i].l]++;
        raz[a[i].r]--;
    }
    vector<int> b(1000002);
    b[0] = raz[0];
    for (int i = 1; i < b.size(); ++i) {
        b[i] = b[i - 1] + raz[i];
    }
    long long sum = 0;
    for (int i = 0; i < 3600; ++i) {
        sum += b[i];
    }
    for (int i = 3600; i < b.size(); ++i) {
        if (b[i - 3600] == 1) sum--;
        if (b[i] == 1) sum++;
        if (sum > t) {
            cout << i - 3600 + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}

