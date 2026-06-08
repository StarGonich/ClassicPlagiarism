#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>


using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    if (n == 1 || n == 2){
        cout << -1;
        return 0;
    }
    ll ans = 0;
    vector<int> otv;
    ans = 6;
    n -= 3;
    otv.push_back(1);
    otv.push_back(2);
    otv.push_back(3);
    ll j = 6;
    while (n > 0){
        otv.push_back(j);
        n--;
        ans += j;
        j*=2;
    }
    cout << ans << endl;
    for (int i = 0; i < otv.size(); i++){
        cout << otv[i] << " ";
    }
  /*  ll n, k;
    cin >> n >> k;
    ll r = n + k;
    long double j = 0.5, pr = 2;
    if (r > 2*n){
        cout << 2*n;
        return 0;
    }
    ll nok = k*n, ans;
    for (ll i = n + 2; i <= r; i++){
        ll a = i, b = n;
        while (b != 0){
                a = a % b;
                swap(a, b);
        }
        if ((i*n / a) < nok){
            ans = i;
            nok = i*n/a;
        }
    }
    cout << ans;*/
    return 0;
}
