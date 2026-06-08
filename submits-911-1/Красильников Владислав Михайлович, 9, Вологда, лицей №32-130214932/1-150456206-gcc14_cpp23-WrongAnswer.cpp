#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, y, m, n;
    cin >> t >> m >> y >> n;
    if (t == y && m == n) {
        cout << "0";
    }
    else {
        for (int i = 0; i <= 39; i++) {
            while (t + m < y + n) {
                m++;
                if (t == y && n == m) {
                    if (m = 60) {
                        m = 0;
                        t++;
                    }


                    cout << i;
                }
                break;
            }
        }
    }
}