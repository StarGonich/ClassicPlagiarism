#include <bits/stdc++.h>

using namespace std;

long long nok(long long a, long long b) {
    long long n, p;
    n = a;
    p = b;
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return n * p / a;
}

int main() {
    long long n, k, l, r, minn = LONG_MAX, a, it;
    cin >> n >> k;
    l = n + 1; r = k + n;
    for (int i = l; i <= r; i++) {
        a = nok(n, i);
        if (a < minn) {
            minn = a;
            it = i;
        }
    }
    cout << it;
}
