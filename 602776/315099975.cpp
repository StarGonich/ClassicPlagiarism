#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, p, q;
    cin >> a >> b >> p;
    cin >> c >> d >> q;

    if (a*d - b*c == 0) {
        if (p == q) {
            cout << "Ambiguity\n"; return 0;
        }
        else {
            cout << "Contradiction\n"; return 0;
        }
    }

    float x = (float)(p*d - b*q) / (a*d - b*c);
    float y = (float)(a*q - p*c) / (a*d - b*c);
    if (x < 0 || y < 0) {
        cout << "Not positive\n"; return 0;
    }
    cout << "Success\n";
    cout << x*100 << " " << y*100;
}
