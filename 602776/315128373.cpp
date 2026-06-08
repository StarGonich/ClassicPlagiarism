#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define PI 3.1415926535897932

#define int long long
const int MOD = 1e9 + 7;
const int INF = 1e15;

int P1 = 31;
int MOD1 = 1791791791;

int calc(string s) {
    int h1 = 0;
    for (auto c: s) {
        int cur = c - 'A' + 1;
        h1 = (h1 * P1 + cur) % MOD1;
    }
    return h1;
}

void solve() {
    int tp; cin >> tp;
    string s; cin >> s;

    if (tp == 1) {
        int h1 = calc(s);
        for (int i = 0, x = h1; i < 10; ++i) {
            s.push_back((char)('A' + x % 26));
            x /= 26;
        }
        cout << s << "\n";
    } else {
        int h1 = 0;
        for (int i = 0; i < 10; ++i) {
            h1 = h1 * 26 + (s.back() - 'A');
            s.pop_back();
        }
        int h10 = calc(s);
        if (h10 == h1) {
            cout << s << "\n";
            return;
        }

        int n = s.size();
        vector<int> powers = {1};
        for (int i = 1; i < n; ++i) {
            powers.push_back(powers.back() * P1 % MOD1);
        }
        for (int i = 0; i < n; ++i) {
            char cur = s[i];
            for (char can = 'A'; can <= 'Z'; ++can) {
                int d = (int)can - (int)cur;
                if ((h10 + d * powers[n - i - 1] % MOD1) % MOD1 == h1) {
                    cout << s.substr(0, i) << can << s.substr(i + 1, n - i - 1) << "\n";
                    return;
                }
            }
        }
        cout << s << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Q = 1;
    // cin >> Q;
    while (Q--) {
        solve();
    }
}
