#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin >> n;
    ll t;
    cin >> t;
    vector<pair<ll,ll>> res(n + 1);
    for (int i = 1; i < n + 1; i++){
        cin >> res[i].first >> res[i].second;
    }
    vector<ll> pref(n + 1);
    for (int i = 1; i < n + 1; i++){
        pref[i] = pref[i - 1] + res[i].second - res[i].first;
    }
    for (int i = 1; i < n + 1; i++){
        int l = i;
        int r = n + 1;
        while (l + 1 < r){
            int c = (l + r) / 2;
            if (res[c].first <= res[i].first + 3600){
                l = c;
            }
            else{
                r = c;
            }
        }

        if (pref[l - 1] - pref[i - 1] + min(res[i].first + 3600, res[l].second) > t){
            cout << res[i].first << endl;
            return;
        }
    }
    cout << -1 << endl;
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
