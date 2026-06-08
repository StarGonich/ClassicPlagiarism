#include <bits/stdc++.h>
using namespace std;
#define ll __int128

ll gcd(ll a, ll b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    long long n, k;
    cin >> n >> k;
    ll ans = 1000000000000000000;
    ll res = 1;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ll x = n / i;
            ll p = i * (x + 1);
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
