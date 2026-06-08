#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll k;
    long double n;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        if ((n / i) == floor (n / i) && n / i <= k){
            cout << n + n / i;
            return 0;
        }
    }
    return 0;
}
