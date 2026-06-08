#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll k;
    ll n;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        if ((n / i) * i == n && n / i <= k){
            cout << n + n / i;
            return 0;
        }
    }
    return 0;
}
