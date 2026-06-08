#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n' << 1;
        return 0;
    }
    if (n == 2) {
        cout << -1;
    }
    vector<long long> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    int ans = 6;
    for (int i = v.size(); i < n; i++) {
        v.push_back(v.back() * 2);
        ans += v.back();
    }
    cout << ans << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
