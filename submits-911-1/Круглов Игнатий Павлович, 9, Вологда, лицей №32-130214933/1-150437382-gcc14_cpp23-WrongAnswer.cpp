#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    ll kol = 0;
    if (h2 < h1 || (h1 == h2 && m2 < m1)) {
        while (h1 < 24) {
            if (h1 == m1) {
                kol++;
            }
            else if (h1 == ((m1 % 10) * 10) + m1 / 10) {
                kol++;
            }
            else if (h1 / 10 < h1 % 10 && h1 % 10 < m1 / 10 && m1 / 10 < m1 % 10) {
                kol++;
            }
            m1++;
            if (m1 == 60) {
                m1 = 0;
                h1++;
            }
        }
        h1 = 0;
        while (h1 < h2 || m1 <= m2) {
            if (h1 == m1) {
                kol++;
            }
            else if (h1 == ((m1 % 10) * 10) + m1 / 10) {
                kol++;
            }
            else if (h1 / 10 < h1 % 10 && h1 % 10 < m1 / 10 && m1 / 10 < m1 % 10) {
                kol++;
            }
            m1++;
            if (m1 == 60) {
                m1 = 0;
                h1++;
            }
        }
    }
    else {
        while (h1 < h2 || m1 <= m2) {
            if (h1 == m1) {
                kol++;
            }
            else if (h1 == ((m1 % 10) * 10) + m1 / 10) {
                kol++;
            }
            else if (h1 / 10 < h1 % 10 && h1 % 10 < m1 / 10 && m1 / 10 < m1 % 10) {
                kol++;
            }
            m1++;
            if (m1 == 60) {
                m1 = 0;
                h1++;
            }
        }
    }
    cout << kol;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("", "r", inout)

    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
}
