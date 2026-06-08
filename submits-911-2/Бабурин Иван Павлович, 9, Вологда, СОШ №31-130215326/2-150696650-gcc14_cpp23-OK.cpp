#include <bits/stdc++.h>
using namespace std;

int main() {
    double p1, p2, p3;
    cin >> p1 >> p2 >> p3;

    double ans =
        p1*p2*(1-p3) +
        p1*p3*(1-p2) +
        p2*p3*(1-p1) +
        p1*p2*p3;

    cout << fixed << setprecision(10) << ans;
}
