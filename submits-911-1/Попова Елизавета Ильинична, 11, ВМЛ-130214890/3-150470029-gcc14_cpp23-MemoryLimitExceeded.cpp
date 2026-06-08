#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
//#pragma GCC target("avx2,fma")
//#define pb push_back
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    vector<int> a(n*2+1);
    a[0] = 0;
    int mx = 0;
    for (int i = 1; i<n*2+1; i+=2){
        int t1,t2;
        cin >> t1 >> t2;
        a[i] = t1;
        a[i+1] = t2;
        mx = t2;
    }
    if (mx<3600){
        cout << "-1";
        return 0;
    }
    vector<int> pref(mx+1);
    pref[0] = 0;

    for (int j = 1; j<a.size()-1; ++j){
        if (j%2 != 0){

            for (int i = a[j]+1; i<=a[j+1]; ++i){
                pref[i] = pref[i-1]+1;
            }
        }
        else {
            for (int i = a[j]+1; i<=a[j+1]; ++i){
                pref[i] = pref[i-1];
            }
        }

    }
    for (int i = 0; i<pref.size()-3600; ++i){
        if (pref[i+3600]-pref[i]>t){
            cout << i;
            return 0;
        }

    }
    cout << "-1";
    return 0;
}
