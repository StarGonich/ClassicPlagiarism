#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, res;
    cin >> n >> k;
    res = n;
    vector<ll> factors;
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            n/=i;
            factors.push_back(i);
        }
    }
    if(n != 1) factors.push_back(n);
    ll now = 1;
    for(int i = factors.size() - 1; i >= 0; i--) {
        if(now * factors[i] + res <= res + k) {
            now *= factors[i];
        }
        else break;
    }
    if(now == 1) cout << res + 1;
    else cout<< res + now;
    return 0;
}
