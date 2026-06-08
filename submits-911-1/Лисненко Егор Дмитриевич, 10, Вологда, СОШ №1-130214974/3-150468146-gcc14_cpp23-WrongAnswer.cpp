#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin >> n;

    vector<ll> a(1000005);
    ll t;
    cin >> t;

    for (int i = 0 ;i < n; i++){
        int l, r;
        cin >> l >> r;
        a[l]= 1;
        a[r]= -1;
    }
    for (int i = 1; i < a.size(); i++){
        a[i] = a[i - 1] + a[i];
    }

    vector<ll> pref(a.size());
    pref[0] = a[0];
    for(int i = 1; i < a.size(); i++){
        pref[i] = pref[i - 1] + a[i];
    }

    for (int i = 0; i < a.size() - 3600; i++){
        if (pref[i + 3599] - pref[i - 1] > t){
            cout << i << endl;
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
