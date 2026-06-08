#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll ans = n + 1, nk = lcm(n + 1, n);
    for(int i = n + 2; i <= n + k; i++) {
        if(lcm(n, n + i) < nk) {
            nk = lcm(n,n+i);
            ans = n + i;
        }
    }
    cout<< ans;
    return 0;
}
