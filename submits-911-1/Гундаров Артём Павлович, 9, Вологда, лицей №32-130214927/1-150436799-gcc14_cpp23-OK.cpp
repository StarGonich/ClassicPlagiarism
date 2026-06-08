#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);

    int ans = 0;

    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int t1 = 60 * h1 + m1, t2 = 60 * h2 + m2;

    if (t1 > t2) {
        for (int i = t1; i <= 24 * 60; i++) {
            int h = i / 60, m = i % 60;
            string fi = "  ", se = "  ";
            fi[0] = h / 10; fi[1] = h % 10;
            se[0] = m / 10; se[1] = m % 10;
            if (fi == se) ans++;
            else if (fi[0] == se[1] && fi[1] == se[0]) ans++;
            else if (fi[0] - '0' == fi[1] - '0' - 1 && fi[1] - '0' == se[0] - '0' - 1 && se[0] - '0' == se[1] - '0' - 1) ans++;
            //cout << fi << " " << se << '\n';
        }
        for (int i = 0; i <= t2; i++) {
            int h = i / 60, m = i % 60;
            string fi = "  ", se = "  ";
            fi[0] = h / 10; fi[1] = h % 10;
            se[0] = m / 10; se[1] = m % 10;
            if (fi == se) ans++;
            else if (fi[0] == se[1] && fi[1] == se[0]) ans++;
            else if (fi[0] - '0' == fi[1] - '0' - 1 && fi[1] - '0' == se[0] - '0' - 1 && se[0] - '0' == se[1] - '0' - 1) ans++;
            //cout << fi << " " << se << '\n';
        }
        cout << ans;
        return 0;
    }
    for (int i = t1; i <= t2; i++) {
        int h = i / 60, m = i % 60;
        string fi = "  ", se = "  ";
        fi[0] = h / 10; fi[1] = h % 10;
        se[0] = m / 10; se[1] = m % 10;
        if (fi == se) ans++;
        else if (fi[0] == se[1] && fi[1] == se[0]) ans++;
        else if (fi[0] - '0' == fi[1] - '0' - 1 && fi[1] - '0' == se[0] - '0' - 1 && se[0] - '0' == se[1] - '0' - 1) ans++;
        //cout << fi << " " << se << '\n';
    }

    cout << ans;

    return 0;
}
