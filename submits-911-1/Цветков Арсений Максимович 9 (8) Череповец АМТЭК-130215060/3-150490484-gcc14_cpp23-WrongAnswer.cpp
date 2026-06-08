#include <bits/stdc++.h>
using namespace std;


void solve2(){
    int n;
    cin >> n;
    int t;
    cin >> t;
    int tt, ttt;
    vector <pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> tt >> ttt;
        v[i].first = tt;
        v[i].second = ttt;
    }
    map <int, int> m;
    for (int i = 0; i < n; i++) {
        for (int j = v[i].first; j <= v[i].second; j++) {
            m[j] = 1;
        }
    } //input


    int now = 0;
    int l = 0;
    int r = 0;

    while (r <  min(v.back().second, 3600)) {
        if (m[r] == 1) {
            now++;
        }
        r++;
    }
    // firs part

    //cout << now;
    // for (int i = 0; i < m.size(); i++) {
    //     cout << m[i] << " ";
    // }

    // remai
    while (r < max(v.back().second, 3600)) {
        if (now > t) {
            cout << l + 1;
            return;
        }
        now -= m[l];
        now += m[r];
        r++;
        l++;
    }
    cout << -1;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve2();
}
