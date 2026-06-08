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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt1 = 0;
    for (int i = 0; i < n-1; i++) {
        if (a[i] > a[i + 1]) {
            cnt1++;
        }
    }
    int c = -1;
    int r = -1;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            c = i + 1;

            int k = c;
            for (int j = 0; j < k && r == -1; j++) {
                if (a[j] > a[k]) {
                    r = j + 1;
                    while (a[j] > a[k]) {
                        cnt++;
                        k++;

                        if (k == n) {
                            break;
                        }
                    }
                }
            }
        }
        
    }

    if (c == -1 || cnt1>1) {
        cout << -1;
        return;
    }
    cout << r << ' ' << c + 1 - r << endl;
    cout << c + 1 << ' ' << cnt;
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
