#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    long long time1 = h1 * 60 + m1;
    long long time2 = h2 * 60 + m2;
    long long ans = 0;
    for(long long i = time1; i <= time2; ++i) {
        long long t1 = i / 60;
        long long t2 = i % 60;
        if ((t1 / 10 == t2 / 10 && t1 % 10 == t2 % 10) || (t1 / 10 == t2 % 10 && t1 % 10 == t2 / 10) || (t1 / 10 + 1 == t1 % 10 && t1 % 10 + 1 == t2 / 10 && t2 / 10 + 1 == t2 % 10)) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
