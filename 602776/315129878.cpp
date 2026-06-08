#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define PI 3.1415926535897932

#define int long long

//int P1 = 31;
//int MOD1 = 1791791791;
//int P2 = 29;
//int MOD2 = 1e9 + 9;
int P1 = 31;
int MOD1 = 11786569;
int P2 = 29;
int MOD2 = 11789377;

int calc(const string& s, int P, int MOD) {
    int h = 0;
    for (auto c: s) {
        int cur = c - 'A' + 1;
        h = (h * P + cur) % MOD;
    }
    return h;
}

void solve() {
    int tp; cin >> tp;
    string s; cin >> s;

    if (tp == 1) {
        int h1 = calc(s, P1, MOD1);
        int h2 = calc(s, P2, MOD2);
        for (int i = 0, x = h1; i < 5; ++i) {
            s.push_back((char)('A' + x % 26));
            x /= 26;
        }
        for (int i = 0, x = h2; i < 5; ++i) {
            s.push_back((char)('A' + x % 26));
            x /= 26;
        }
        cout << s << "\n";
    } else {
        int h1 = 0, h2 = 0;
        for (int i = 0; i < 5; ++i) {
            h2 = h2 * 26 + (s.back() - 'A');
            s.pop_back();
        }
        for (int i = 0; i < 5; ++i) {
            h1 = h1 * 26 + (s.back() - 'A');
            s.pop_back();
        }
        int h10 = calc(s, P1, MOD1);
        int h20 = calc(s, P2, MOD2);
        if (h10 == h1 && h20 == h2) {
            cout << s << "\n";
            return;
        }

        int n = s.size();
        vector<int> p1 = {1};
        auto p2 = p1;
        for (int i = 1; i < n; ++i) {
            p1.push_back(p1.back() * P1 % MOD1);
            p2.push_back(p2.back() * P2 % MOD2);
        }
        for (int i = 0; i < n; ++i) {
            char cur = s[i];
            for (char can = 'A'; can <= 'Z'; ++can) {
                int d = (int)can - (int)cur;
                if ((h10 + d * p1[n - i - 1] % MOD1) % MOD1 == h1 && (h20 + d * p2[n - i - 1] % MOD2) % MOD2 == h2) {
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
