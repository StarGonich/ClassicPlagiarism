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
    long long n, k, l, r, minn = LONG_MAX, mid;
    cin >> n >> k;
    l = n + 1; r = k + n;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (nok(n, mid) < minn) {
            minn = mid;
            l = mid;

        } else {
            r = mid;
        }

    }
    cout << mid;
}
