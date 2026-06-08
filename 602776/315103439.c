#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int MOD = 1000000007;


void do_stuff() {
    int n, i, j, r, g, a, b, p, c, d, q, D, Dy, Dx;

    cin >> a >> b >> p >> c >> d >> q;
    D = a * d - b * c;
    Dx = p * d - b * q;
    Dy = a * q - p * c;

    if(D == 0) {
        if(Dy == 0) {
            cout << "Ambiguity" << endl;
        } else {
            cout << "Contradiction" << endl;
        }
    } else {
        double y = 100 * (double)Dy / D;
        double x = 100 * (double)Dx / D;

        if(x > 0 and y > 0) {
            cout << "Success" << endl;
            cout << setprecision(10) << x << " " << y << endl;
        } else {
            cout << "Not positive" << endl;
        }
    }
}

signed main() {
    int t = 1;

    //cin >> t;
    while(t--) {
        do_stuff();
    }
}