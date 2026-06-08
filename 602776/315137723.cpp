#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, pos1, len1 = 0, pos2, len2 = 0;
    cin >> n;

    vector<int> a(n + 1), b = {0};
    for (int i = 1; i <= n; i++) cin >> a[i];

    int i = 1;
    while (i < n && a[i] == i) {
        b.push_back(i);
        i++;
    }

    if (i == n) {
        cout << -1 << '\n';
        return 0;
    }

    pos1 = i;

    int j = i;
    while (j <= n && a[j] != i) j++;

    pos2 = j;

    int x = i;
    while (j <= n && a[j] == x) {
        b.push_back(x);
        len2++;
        j++;
        x++;
    }

    vector<int> tmp;
    while (i < pos2) {
        tmp.push_back(a[i]);
        len1++;
        i++;
        if (a[i - 1] == j - 1) break;
    }

    for (int k = i; k < pos2; k++) b.push_back(a[k]);
    for (auto y : tmp) b.push_back(y);
    for (int k = pos2 + len2; k <= n; k++) b.push_back(a[k]);

    bool flag = true;

    for (int i = 1; i <= n; i++) {
        if (b[i] != i) {
            flag = false;
            break;
        }
    }

    if (!flag) {
        cout << -1 << '\n';
        return 0;
    }

    cout << pos1 << ' ' << len1 << '\n';
    cout << pos2 << ' ' << len2 << '\n';
}
