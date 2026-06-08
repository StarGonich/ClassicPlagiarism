#include <bits/stdc++.h>
using namespace std;
string conv(int x) {
    string rs = "";
    while (x > 0) {
        rs += char('0' + x % 10);
        x /= 10;
    }
    reverse(rs.begin(), rs.end());
    while (rs.size() < 2) {
        rs = '0' + rs;
    }
    return rs;
}
bool good(int x, int y) {
    string fir = conv(x);
    string sec = conv(y);
    if (conv(x) == conv(y)) return true;
    reverse(sec.begin(), sec.end());
    if (fir == sec) return true;
    if (fir[0] + 1 == fir[1] && fir[1] + 1 == sec[0] && sec[0] + 1 == sec[1]) return true;
    return false;
}
int main() {
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int ans = 0;
    while (true) {
        ans += good(h1, m1);
        if (h1 == h2 && m1 == m2) break;
        m1++;
        if (m1 == 60) {
            m1 = 0;
            h1++;
        }
        if (h1 == 24) {
            h1 = 0;
        }
    }
    cout << ans;
    return 0;
}
