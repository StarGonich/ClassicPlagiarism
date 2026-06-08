#include <bits/stdc++.h>

using namespace std;

#define ll long long


vector<bool> explosed(1e5, false);

void rec(ll k, vector<ll>& x, vector<ll>& d){
    int i = 0;
    while(x[k] + d[k] >= x[i]){
        if(!explosed[i] && (x[i] >= x[k] - d[k])){
            explosed[i] = true;
            rec(i, x, d);
        }
        i++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> d(n);
    vector<ll> crossed(n);

    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    for(int i = 0; i < n; i++){
        cin >> d[i];

    }

    ll k;
    cin >> k;
    k--;
    explosed[k] = true;
    rec(k, x, d);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(explosed[i]){
            ans++;
        }
    }
    cout << ans;

}
