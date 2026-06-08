#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll n, t;
    cin >> n >> t;
    vector<ll> t1(n);
    vector<ll> t2(n);
    for (int i = 0; i < n; ++i){
        cin >> t1[i] >> t2[i];
    }
    ll x = t2[n - 1];
    vector<ll> adc(x);
    for (int i = 0; i < n; ++i){
        for (int j = t1[i]; j < t2[i]; ++j){
            adc[j] = 1;
        }
    }
    while(adc.size() < 3600){
        adc.push_back(0);
    }
    int our = 0;
    for (int i = 0; i < 3600; ++i){
        our += adc[i];
    }
    for (int l = 3600; l < adc.size(); ++l){
        if (our > t){
            cout << l - 3599;
            return 0;
        }
        our += adc[l] - adc[l - 3599];
    }
    if (our > t){
            cout << adc.size() - 3600;
            return 0;
        }
    cout << -1;
    return 0;
}
