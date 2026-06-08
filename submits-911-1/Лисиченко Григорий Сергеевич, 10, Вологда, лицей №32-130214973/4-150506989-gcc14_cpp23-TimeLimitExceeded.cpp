#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>


using namespace std;
using ll = long long;
int main()
{
    ll n, k;
    cin >> n >> k;
    ll r = n + k;
    long double j = 0.5, pr = 2;
    if (r > 2*n){
        cout << 2*n;
        return 0;
    }
    ll nok = r*n + 1, ans;
    for (ll i = n + 1; i <= r; i++){
        ll a = i, b = n;
        while (b != 0){
                a = a % b;
                swap(a, b);
        }
        if ((i*n / a) < nok){
            ans = i;
            nok = (i*n)/a;
        }
    }
    cout << ans;
    return 0;
}
