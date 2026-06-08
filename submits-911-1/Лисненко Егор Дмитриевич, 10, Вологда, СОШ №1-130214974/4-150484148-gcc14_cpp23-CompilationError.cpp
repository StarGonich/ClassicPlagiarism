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
    ll p = -1;
    for (ll i = 2; i * i <= n; i++){
        if (n % i == 0){
            p = i;
            break;
        }
    }
    ll g = (n / p * (p + 1));
    ll res = 0;
    ll d = 10000000000;
    for(ll i = n + 1; i <= min(n + k, 100000000); i++){
        if (lcd(n, i) < d){
            d = lcd(n, i);
            res = i;
        }
    }
    cout << min(g, res) << endl;
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
