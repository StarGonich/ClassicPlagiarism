#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    //vector<bool> ans(n);
    ll k = 0;
    ll k20 = 0;
    while(k + 20 <= n){
        k += 20;
        k20++;
    }

    k = 0;
    ll k30 = 0;
    while(k + 30 <= n){
        k += 30;
        k30++;
    }

    k = 0;
    ll k12 = 0;
    while(k + 12 <= n){
        k += 12;
        k12++;
    }

    ll ans = n/4;
    ans -= k12;
    ans -= k20;
    ans += n/6;
    ans -= k12;
    ans -= k30;
    ans += n/5;
    ans -= k20;
    ans -= k30;
    cout << ans;
}
