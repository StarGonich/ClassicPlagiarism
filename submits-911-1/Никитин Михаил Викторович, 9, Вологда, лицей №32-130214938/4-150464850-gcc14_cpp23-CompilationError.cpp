#include <bits/stdc++.h>
using namespace std;
#define ll long long

__int128 gcd(__int128 a, __int128 b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    long long n1, k1;
    cin >> n1 >> k1;
    __int128 n = n1, k = k1;
    __int128 ans = 100000000000000000000000000000;
    __int128 res = 1;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            __int128 x = n / i;
            __int128 p = i * (x + 1);
            if (p <= n + k) {
                if (ans > n * p / gcd(n, p)) {
    	            ans = n * p / gcd(n, p);
        	        res = p;
            	}
            }
            p = x * (i + 1);
            if (p > n + k) {
                continue;
            }
            if (ans > n * p / gcd(n, p)) {
                ans = n * p / gcd(n, p);
                res = p;
            }
   		}
    }
    cout << res;
    return 0;
}
