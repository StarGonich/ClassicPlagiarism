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
    if (r >= 2*n){
        cout << 2*n;
        return 0;
    }
    ll o = 2;
    while (n % o != 0){
        o++;
    }
    if (o != n){
    ll u = o + 1;
    bool l = false;
    while (l == 0){
        for (int i = 2; i*i <= u; i++){
            if (u % i == 0){
                break;
            }
            if ((i + 1)*(i + 1) > u){
                l = 1;
            }
        }
        u++;
    }
    ll p = (n / o)*(u - 1);
    if (p <= r){
        cout << p;

        return 0;
    }
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
