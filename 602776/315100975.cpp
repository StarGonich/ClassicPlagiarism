#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, d, p, q, x, y;
    cin >> a >> b >> p >> c >> d >> q;

    double del = a * d - c * b, d1 = p * d - q * b, d2 = a * q - c * p;

    if (del == 0) {
        double k;
        if (a != 0) {
            k = c / a;
        }
        else {
            k = d / b;
        }

        if (fabs(q - k * p) > 0.000001) {
            cout << "Contradiction" << endl;
        }
        else {
            cout << "Ambiguity" << endl;
        }
    }
    else {
        x = d1 / del, y = d2 / del;

        if (x - 0.000001 < 0 || y - 0.000001 < 0) {
            cout << "Not positive" << endl;
        }
        else {
            cout << "Success" << endl;
            cout << x * 100 << " " << y * 100 << endl;
        }
    }
}