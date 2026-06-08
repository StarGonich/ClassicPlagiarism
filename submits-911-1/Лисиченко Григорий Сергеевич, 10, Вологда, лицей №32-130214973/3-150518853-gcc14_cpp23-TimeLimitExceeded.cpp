#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;
int main()
{
    ll n, t, mx = 0;
    cin >> n >> t;
    vector<pair<ll, ll>> a(n);
    vector<int> pole(1'000'000, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        for (ll j = a[i].first; j < a[i].second;j++){
                pole[j] = 1;
        }
        mx = max(mx, a[i].second);
    }
    ll sum = 0, u = 0;
    while (sum <= t && u + 3600 - 1 <= mx){
            sum = 0;
        for (int i = u; i < u + 3600; i++){
            sum+=pole[i];
        }
        u++;
    }
    if (sum > t){
        cout << u - 1;
    }
    else {
        cout << -1;
    }
    return 0;
}