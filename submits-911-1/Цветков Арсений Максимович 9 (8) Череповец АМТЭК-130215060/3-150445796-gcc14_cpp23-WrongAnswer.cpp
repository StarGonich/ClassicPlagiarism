#include <bits/stdc++.h>
using namespace std;


void solve(){
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
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}