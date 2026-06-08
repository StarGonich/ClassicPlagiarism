#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
    }
    else if (n == 2) {
        cout << -1;
    }
    else {
        cout << n << '\n';
        cout << n * 6 / 2 << " ";
        if (n * 6 % 2 == 0) {
            for (int i = n * 6 / 4; i >= 2; i--) {
                if (n * 6 % i == 0) {
                    cout << i << " ";
                }
            }
        } else {
            cout << n * 6 / 2  << " ";
            for (int i = n * 6 / 4; i >= 1; i--) {
                if (n * 6 % i == 0) {
                    cout << i << " ";
                }
        }
    }
}
}