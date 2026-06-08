#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if (a < b){
        swap(a,b);
    }
    while(b > 0){
        a %= b;
        swap(a,b);
    }
    return a;
}

ll lcd(ll a, ll b){
    return a * b / gcd(a,b);
}

void solve(){
    ll n, k;
    cin >> n >> k;
    ll d = 100000000000;
    ll res = -1;
    for (ll i = n + 1; i <= min({50000000LL, 2 * n, n + k}); i++){
        if (lcd(n, i) < d){
            d = lcd(n, i);
            res = i;
        }
    }

    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--){
        solve();
    }
    return 0;
}
