#include <iostream>
using namespace std;

int main()
{
    double a, b, p, c, d, q;
    cin >> a >> b >> p >> c >> d >> q;
    if ((a / c == b / d) &(b / d != p / q)){
        cout << "Contradiction";
        return 0;
    }
    if ((a / c != b / d) &(b / d == p / q)){
        cout << "Contradiction";
        return 0;
    }
    if ((a / c == b / d) &(b / d == p / q)){
        cout << "Ambiguity";
        return 0;
    }
    double x, y;
    y = (q / d - (p * c)/(a * d)) / (1 - (b * c) / (a * d));
    x = (p - y * b)/a;
    if (x > 0 & y > 0)
        cout << "Success" << endl << x * 100 << " " << y * 100;
    else{
        cout << "Not positive";
    }
}
