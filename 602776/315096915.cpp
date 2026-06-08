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
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 4 == 0 && i % 6 != 0 && i % 5 != 0) {
            cnt++;
        }
        if (i % 4 != 0 && i % 6 == 0 && i % 5 != 0) {
            cnt++;
        }
        if (i % 4 != 0 && i % 6 != 0 && i % 5 == 0) {
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
