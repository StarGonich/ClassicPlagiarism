#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] != i + 1) {
            if (l == -1) l = i;
            r = i;
        }
    }
    if (l == -1) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> w;
    for (int i = l; i <= r; i++) {
        w.push_back(v[i]);
    }
    int mw = w.size();
    int S = l + 1;
    vector<int> len(mw, 1);
    for (int i = mw - 2; i >= 0; i--) {
        if (w[i] + 1 == w[i + 1]) {
            len[i] = len[i + 1] + 1;
        }
        else {
            len[i] = 1;
        }
    }

    for (int k = 1; k < mw; k++) {
        int len2 = mw - k;
        if (w[k] != S) continue;
        if (len[k] < len2) continue;

        int start = S + len2;
        if (w[0] != start) continue;
        if (len[0] < k) continue;
        int pos1 = l + 1;
        int ln1 = k;
        int pos2 = l + k + 1;
        int ln2 = len2;
        cout << pos1 << " " << ln1 <<endl;
        cout << pos2 << " " << ln2 <<endl;
        return 0;
    }

    cout << -1 << endl;
    return 0;
}
