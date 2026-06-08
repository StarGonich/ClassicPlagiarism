#include <bits/stdc++.h>
using namespace std;

void factor(int n) {
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    if (n == 2) {
        cout << 2;
        return;
    }
    if (n == 3) {
        cout << 3;
        return;
    }
    while (n % 2 == 0) {
        cout << 2 << " ";
    }

}

void solve(){
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << "\n" << 1;
    }
    else if (n == 3) {
        cout << 6 << "\n" << 1 << " " << 2 << " " << 3;
    } else
        cout << -1;

}

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
    int i = 0;
    int now = 0;
    int l = 0;
    int r = min(v.back().second, 3600);
    while (v[i].first <= r) {
        now += min(v[i].second - max(v[i].first, l), r);
        i++;
    }
    if (now <= t) {
        cout << 0;
    }
    


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve2();
}
