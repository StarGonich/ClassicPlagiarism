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
    vector<int> factors;
    for(int i = 2; i  <= n; i++) {
        while(n%i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    for(int i = factors.size() - 1; i >= 0; i--) {
        if(k >= factors[i]) {
            ll ans = res;
            while(ans <= res + k) {
                ans += factors[i];
            }
            if(ans > n + k) ans-=factors[i];
            cout << ans;
            return 0;
        }
    }
    cout << res + 1;
    return 0;
}
