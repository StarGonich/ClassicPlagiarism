#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <utility>

using namespace std;

bool watch (int a, int b) {
    if (a == 0 && b == 0) {
        return true;
    }
    if (a == 1 && b == 1) {
        return true;
    }
    if (a == 1 && b == 10) {
        return true;
    }
    if (a == 1 && b == 23) {
        return true;
    }
    if (a == 2 && b ==2) {
        return true;
    }
    if (a == 2 && b == 20) {
        return true;
    }
    if (a == 3 && b == 3) {
        return true;
    }
    if (a == 3 && b == 30) {
        return true;
    }
    if (a == 4 && b == 4) {
        return true;
    }
    if (a == 4 && b == 40) {
        return true;
    }
    if (a == 5 && b == 5) {
        return true;
    }
    if (a == 5 && b == 50) {
        return true;
    }
    if (a == 6 && b == 6) {
        return true;
    }
    if (a == 7 && b == 7) {
        return true;
    }
    if (a == 8 && b == 8) {
        return true;
    }
    if (a == 9 && b == 9) {
        return true;
    }
    if (a == 10 && b == 10) {
        return true;
    }
    if (a == 10 && b == 1) {
        return true;
    }
    if (a == 11 && b == 11) {
        return true;
    }
    if (a == 12 && b == 12) {
        return true;
    }
    if (a == 12 && b == 21) {
        return true;
    }
    if (a == 12 && b == 34) {
        return true;
    }
    if (a == 13 && b == 13) {
        return true;
    }
    if (a == 13 && b == 31) {
        return true;
    }
    if (a == 14 && b == 14) {
        return true;
    }
    if (a == 14 && b == 41) {
        return true;
    }
    if (a == 15 && b == 15) {
        return true;
    }
    if (a == 15 && b == 51) {
        return true;
    }
    if (a == 16 && b == 16) {
        return true;
    }
    if (a == 17 && b == 17) {
        return true;
    }
    if (a == 18 && b == 18) {
        return true;
    }
    if (a == 19 && b == 19) {
        return true;
    }
    if (a == 20 && b == 20) {
        return true;
    }
    if (a == 20 && b == 02) {
        return true;
    }
    if (a == 21 && b == 21) {
        return true;
    }
    if (a == 21 && b == 12) {
        return true;
    }
    if (a == 22 && b == 22) {
        return true;
    }
    if (a == 23 && b == 23) {
        return true;
    }
    if (a == 23 && b == 32) {
        return true;
    }
    if (a == 23 && b == 45) {
        return true;
    }
    return false;
}

int main()
{
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int k = 0;
    if ((h1 == h2) && (m1 <= m2)) {
        for (int m = m1; m <= m2; ++m) {
            if (watch(h1, m)) {
                k++;
            }
        }
        cout << k;
        return 0;
    }
    if (h1 < h2) {
        for (int m = m1; m <= 59; ++m) {
            if (watch(h1, m)) {
                k++;
            }
        }
        for (int h = h1 + 1; h < h2; ++h) {
            for (int m = 0; m <= 59; ++m) {
                if (watch(h, m)) {
                    k++;
                }
            }
        }
        for (int m = 0; m <= m2; ++m) {
            if (watch(h2, m)) {
                k++;
            }
        }
        cout << k;
        return 0;
    }
    for (int m = m1; m <= 59; ++m) {
        if (watch (h1, m)) {
            k++;
        }
    }
    for (int h = h1 + 1; h <= 23; ++h) {
        for (int m = 0; m <= 59; ++m) {
            if (watch(h, m)) {
                k++;
            }
        }
    }
    for (int h = 0; h < h2; ++h) {
        for (int m = 0; m <= 59; ++m) {
            if (watch(h, m)) {
                k++;
            }
        }
    }
    for (int m = 0; m <= m2; ++m) {
        if (watch(h2, m)) {
            k++;
        }
    }
    cout << k;


    return 0;
}
