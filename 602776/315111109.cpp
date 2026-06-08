#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
    ld a, b, c, d, b1, b2;
    cin >> a >> b >> b1 >> c >> d >> b2;

    ld x, y;

    if (a == 0 || b == 0 || c == 0 || d == 0) {
        if (a == 0 && b == 0 || c == 0 && d == 0) {
            cout << "Contradiction\n";
            return 0;
        }

        if (a == 0 && c == 0) {
            if (b1 / b != b2 / d)
                cout << "Contradiction\n";
            else
                cout << "Ambiguity\n";
            return 0;
        }

        if (b == 0 && d == 0) {
            if (b1 / a != b2 / c)
                cout << "Contradiction\n";
            else
                cout << "Ambiguity\n";
            return 0;
        }

        if (a == 0 && d == 0) {
            x = b2 / c;
            y = b1 / b;
            cout << "Success\n";
            cout << fixed << setprecision(3) << 100 * x << ' ' << 100 * y << '\n';
            return 0;
        }

        if (b == 0 && c == 0) {
            x = b1 / a;
            y = b2 / d;
            cout << "Success\n";
            cout << fixed << setprecision(3) << 100 * x << ' ' << 100 * y << '\n';
            return 0;
        }

        if (a == 0) {
            y = b1 / b;
            x = (b2 - d * y) / c;
        }

        if (b == 0) {
            x = b1 / a;
            y = (b2 - c * x) / d;
        }

        if (c == 0) {
            y = b2 / d;
            x = (b1 - b * y) / a;
        }

        if (d == 0) {
            x = b2 / c;
            y = (b1 - a * x) / b;
        }

        if (x < 0 || y < 0) {
            cout << "Not positive\n";
            return 0;
        }

        cout << "Success\n";
        cout << fixed << setprecision(3) << 100 * x << ' ' << 100 * y << '\n';

        return 0;
    }

    if (a == b && c == d && b1 != b2) {
        cout << "Contradiction\n";
        return 0;
    }

    if (a == b && c == d && b1 == b2) {
        cout << "Ambiguity\n";
        return 0;
    }

    y = (b2 - c / a * b1) / (d - c / a * b);
    x = (b1 - b * y) / a;

    if (x < 0 || y < 0) {
        cout << "Not positive\n";
        return 0;
    }

    cout << "Success\n";
    cout << fixed << setprecision(3) << 100 * x << ' ' << 100 * y << '\n';

    return 0;
}

