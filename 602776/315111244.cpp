#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int i = 1, pos1, len1 = 0, pos2, len2 = 0;
    while (i <= n) {
        if (a[i] != i) {
            pos1 = i;
            int j = i;
            while (j < n && a[j] != i) j++;
            pos2 = j;
            vector<int> fi, se;
            while (j < n && a[j] != j) {
                se.push_back(a[j]);
                j++;
                len2++;
            }
            while (i < pos2 && a[i] != i) {
                fi.push_back(a[i]);
                i++;
                len1++;
            }
            vector<int> b = {0};
            for (int k = 1; k < pos1; k++) b.push_back(a[k]);
            for (auto x : se) b.push_back(x);
            for (int k = pos1 + len1; k < pos2; k++) b.push_back(a[k]);
            for (auto x : fi) b.push_back(x);
            for (int k = pos2 + len2; k <= n; k++) b.push_back(a[k]);
            bool flag = true;
            for (int k = 1; k <= n; k++) {
                if (b[k] != k) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << pos1 << ' ' << len1 << '\n' << pos2 << ' ' << len2 << '\n';
                return 0;
            } else break;
        } else i++;
    }
    cout << -1 << '\n';
}
