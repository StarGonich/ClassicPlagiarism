#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>


using namespace std;
using ll = long long;
int main()
{
    ll h1, m1, h2, m2, ans = 0;
    cin >> h1 >> m1 >> h2 >> m2;
    ll mh1 = h1*60 + m1, mh2 = h2*60 + m2;
    for (int i = mh1; i <= mh2; i++){
        ll h = i / 60, m = i % 60;
        if (h == m){
            ans++;
        }
        ll r = (m % 10)*10 + (m / 10);
        if (h == r){
            ans++;
        }
        if (h == 1 || h == 12 || h == 23){
            if (m == h + 22){
                ans++;
            }
        }
    }
    cout << ans;

    /*int n;
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
    */
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
