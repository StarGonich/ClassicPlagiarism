#include <bits/stdc++.h>

#define fi first
#define se second
#define all(x) x.begin(), x.end()

#define int ll

using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

void solve() {
    int a, b, p;
    int c, d, q;
    cin >> a >> b >> p;
    cin >> c >> d >> q;

    int D = a * d - b * c;
    if (D == 0) {
        if (a * q == c * p)
            cout << "Ambiguity";
        else
            cout << "Contradiction";
        return;
    }

    int Dx = p * d - b * q;
    int Dy = a * q - p * c;

    Dx *= 100;
    Dy *= 100;

    if (D * Dx < 0 || D * Dy < 0) {
        cout << "Not positive";
        return;
    }

    cout << "Success\n";
    cout << fixed << setprecision(10) << 1.0 * Dx / D << ' ' << 1.0 * Dy / D;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t --> 0) {
        solve();
        cout << '\n';
    }

    return 0;
}
