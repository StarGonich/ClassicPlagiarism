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

const int MOD = 141167095653376;
const int K = 27;
const int L = 10;

int code(char c) {
    return c - 'A' + 1;
}

int find_hash(string &s) {
    int n = (int)s.size();
    int h = 0;
    int k = 1;
    for (int i = 0; i < n; i++) {
        h += (k * code(s[i])) % MOD;
        h %= MOD;
        k = (k * K) % MOD;
    }

    return h;
}

int str_to_hash(string s) {
    int h = 0;
    int k = 1;
    reverse(all(s));
    for (int i = 0; i < L; i++) {
        h += (s[i] - 'A') * k;
        k *= 26;
    }

    return h;
}

string hash_to_str(int h) {
    string s = "";
    while ((int)s.size() != L) {
        char c = 'A' + (h % 26);
        h /= 26;
        s += c;
    }

    reverse(all(s));
    return s;
}

void solve() {
    int t; cin >> t;
    string s; cin >> s;

    if (t == 1) {
        string h = hash_to_str(find_hash(s));
        s += h;
        cout << s;
    }
    else {
        int n = (int)s.size();
        string h = s.substr(n-L, L);
        s = s.substr(0, n-L);

        int hs = str_to_hash(h);

        if (find_hash(s) == hs) {
            cout << s;
            return;
        }

        for (int i = 0; i < n-L; i++) {
            string ss = s;
            for (char c = 'A'; c <= 'Z'; c++) {
                ss[i] = c;
                if (find_hash(ss) == hs) {
                    cout << ss;
                    return;
                }
            }
        }

        cout << s;
    }
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
