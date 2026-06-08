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
    if (2 * n <= n + k){
        cout << 2 * n << endl;
        return;
    }
    for (ll i = 2; i * i <= n; i++){
        if (n % i == 0){
            p = i;
            break;
        }
    }
    ll g = (n / p * (p + 1));
    cout << g << endl;
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
