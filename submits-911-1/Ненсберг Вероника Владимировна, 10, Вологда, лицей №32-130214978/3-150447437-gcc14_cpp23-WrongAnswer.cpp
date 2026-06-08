#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int T;
    cin >> T;
    if (T == 3600) {
        cout << -1;
        return 0;
    }
    vector<int> t1(n);
    vector<int> t2(n);
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> t1[i] >> t2[i];
        pref[i + 1] = pref[i] + t2[i] - t1[i];
    }
    for (int i = 0; i < n; i++) {
        if (t2[i] - t1[i] > T) {
            cout << t1[i];
            return 0;
        }
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        r = max(r, i);
        while (r + 1 < n && t2[r + 1] - t1[i] <= 3600) {
            r++;
        }
        int sum = pref[r + 1] - pref[i];
        if (r + 1 < n && t1[r + 1] - t1[i] < 3600) {
            sum += t1[i] + 3600 - t1[r + 1];
        }
        if (sum > T) {
            cout << t1[i];
            return 0;
        }
    }
    cout << -1;
    return 0;
}
