#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    if (n == 1) {
        cout << "1\n1";
        return 0;
    }
    if (n == 2) {
        cout << "-1\n";
        return 0;
    }
    int cur = 6;
    int cnt = 3;
    vector<int> ans = {1, 2, 3};
    while (cnt < n) {
        int x = ans.back();
        ans.emplace_back(x * 2);
        cur += x * 2;
        cnt++;
    }
    cout << cur << "\n";
    for (auto el : ans) cout << el << " ";
    return 0;
}
