#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, y, m, n;
    cin >> t >> m >> y >> n;
    if (t == y && m == n || y == t >= 10 && n - m < 10) {
        cout << "0";
    }
    if (t == y - 1 && m + 10 > n || t == y -2 && m < n){
        cout << 4;
    }
    if (t == y -1 && m < n + 5){
        cout << 3;
    }
    if (t < y - 1 && m > n){
        cout << 6;
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