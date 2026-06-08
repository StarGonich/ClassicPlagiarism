#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin » n;

    long long t;
    vector<long long> divs;

    if (n <= 29) {
        // t = 2^n - 1
        t = (1LL « n) - 1;

        // делители: 1,2,4,...,2^(n-1)
        for (int i = 0; i < n; i++) {
            divs.push_back(1LL « i);
        }
    }
    else {
        // n = 30 — т не может быть 2^30 - 1
        t = (1LL « 29); // t = 2^29 < 10^9

        // первые 29 делителей
        long long sum29 = 0;
        for (int i = 0; i < 29; i++) {
            long long v = (1LL « i);
            divs.push_back(v);
            sum29 += v;
        }

        // 30-й делитель
        long long last = t - sum29;
        divs.push_back(last);
    }

    cout « t « "\n";
    for (long long x : divs) cout « x « " ";
    cout « "\n";

    return 0;
}