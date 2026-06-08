#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i % 4 == 0) {
            a[i]++;
        }
        if (i % 5 == 0) {
            a[i]++;
        }
        if (i % 6 == 0) {
            a[i]++;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            cnt++;
        }
    }
    cout << cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}
