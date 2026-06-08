#include <iostream>
#include <iomanip>

using namespace std;

int gcd(int a, int b) {
    if (!a) return b;
    return gcd(b % a, a);
}

bool eq(double a, double b) {
    return std::abs(a - b) < 1e-9;
}

int main() {
    int a, b, p, c, d, q;
    cin >> a >> b >> p >> c >> d >> q;
    p *= 100;
    q *= 100;

    double fr = (double)a / c;
    if (eq(fr, (double)b / d) && eq(fr, (double)p / q)) {
        cout << "Ambiguity\n";
        return 0;
    }

    if (b * c - a * d == 0) {
        cout << "Contradiction\n";
        return 0;
    }

    double x = (double)(d * p - b * q) / (a * d - b * c);
    double y = (double)(c * p - a * q) / (b * c - a * d);

    if (x <= 0 || y <= 0) {
        cout << "Not positive\n";
        return 0;
    }

    cout << fixed << setprecision(4) << "Success\n" << x << " " << y << "\n";
}