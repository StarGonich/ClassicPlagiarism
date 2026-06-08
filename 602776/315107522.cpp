#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double a, b, p;
    cin >> a >> b >> p;

    double c, d, q;
    cin >> c >> d >> q;

    double v2 = (a * d - b * c) / (a * q - p * c);
    
    double v1 = (a * v2) / (p * v2 - b);
    
    if (a == c && b == d && p != q) {
        cout << "Contradiction\n";
        return 0;
    }
    
    if (v1 == 0.0 || v2 == 0.0) {
        cout << "Contradiction\n";
        return 0;
    }
    
    if ((a * q - p * c) == 0.0) {
        cout << "Ambiguity\n";
        return 0;
    }

    if ((p * v2 - b) == 0.0) {
        cout << "Ambiguity\n";
        return 0;
    }
    
    if (v1 < 0.0 || v2 < 0.0) {
        cout << "Not positive\n";
        return 0;
    }
    
    cout << "Success\n";
    cout << 100.0 / v1 << ' ' << 100.0 / v2 << '\n';
}
