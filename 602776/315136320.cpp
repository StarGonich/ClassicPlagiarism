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

    pos1 = i;

    if (i == n) {
        cout << -1 << '\n';
        return 0;
    }

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
    while (i < pos2 && a[i] != j) {
        tmp.push_back(a[i]);
        len1++;
        i++;
    }

    for (int k = i; i < pos2; i++) b.push_back(a[i]);
    for (auto x : tmp) b.push_back(x);
    for (int i = pos2 + len2; i <= n; i++) b.push_back(a[i]);

    cout << pos1 << ' ' << len1 << '\n';
    cout << pos2 << ' ' << len2 << '\n';
}
