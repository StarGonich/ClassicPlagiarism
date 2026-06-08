#include <iostream>

using namespace std;

string convert_to_str(int x) {
    string s = "";
    while (x) {
        s.push_back(x % 26 + 'A');
        x /= 26;
    }
    while (s.size() < 9) {
        s.push_back('A');
    }
    return s;
}

int convert_to_int(string s) {
    int x = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        x = x * 26 + s[i] - 'A';
    }
    return x;
}

const int P = 29;
const int MOD = 1e9 + 7;
const int N = 2000;
int64_t p[N];
void init() {
    p[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = p[i - 1] * P % MOD;
    }
}
int64_t calc_hash(string s) {
    int64_t res = 0;
    for (int i = 0; i < s.size(); i++) {
        res = (res + p[i] * (s[i] - 'A')) % MOD;
    }
    return res;
}

string encode(string s) {
    int n = s.size();
    int x = calc_hash(s);
    auto h_str = convert_to_str(x);
    s += h_str;
    int kek = 0;
    for (char c : h_str) {
        kek += c - 'A';
    }
    kek %= 26;
    s.push_back(kek + 'A');
    return s;
}

string decode(string s) {
    int n = s.size() - 10;
    auto h_str = s.substr(n, 9);
    int a = convert_to_int(h_str);
    int b = convert_to_int(s.substr(n + 9, 1));

    s = s.substr(0, n);

    int kek = 0;
    for (char c : h_str) {
        kek += c - 'A';
    }
    kek %= 26;
    if (kek != b) {
        return s;
    }

    auto h = calc_hash(s);

    for (int i = 0; i < n; i++) {
        auto val_old = p[i] * (s[i] - 'A') % MOD;
        for (int j = 0; j < 26; j++) {
            auto val = p[i] * j % MOD;
            if ((h + MOD - val_old + val) % MOD == a) {
                s[i] = j + 'A';
                return s;
            }
        }
    }
    return "KARAMBA";
}

int main() {
    init();
    int t;
    cin >> t;
    string s;
    cin >> s;

    if (t == 1) {
        cout << encode(s) << "\n";
    } else {
        cout << decode(s) << "\n";
    }
}