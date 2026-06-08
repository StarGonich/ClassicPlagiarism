#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1;
        return;
    }
    else if (n == 1) {
        cout << 5 << "\n";
        cout << 5;
    }
    else {
        int x = 3;
        vector<int> a;
        a.push_back(3);
        a.push_back(2);
        a.push_back(1);
        ll sum = 6;
        while (x < n) {
            a.push_back(sum);
            sum += sum;
            x++;
        }
        cout << sum << "\n";
        for (auto u : a) {
            cout << u << " ";
        }
        return;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("", "r", inout)

    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
}
