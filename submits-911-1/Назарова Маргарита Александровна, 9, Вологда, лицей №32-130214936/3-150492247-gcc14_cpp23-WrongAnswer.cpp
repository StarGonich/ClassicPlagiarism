#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;
using ll =long long;
const int h = 3600;

int main()
{
    int n; ll t;
    cin >> n >> t;
    vector <pair <ll, ll>> a(n+1);
    map <int, int> m;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        m[a[i].first] = 0;
        m[a[i].second] = 1;
    }
    ll l = 0, r = 3600;
    ll ansl = 0;
    ll ans = 0;
    ll mxans = 0;
    ll pr0 = 0, pr1 = 0;
    for(auto [k, v]:m){
        if(v==0){
            if(k-pr0>h){
                ans = 0;
            }
            pr0 = k;
        }
        else{
            if(k-pr1>h){
                ans+=k-pr0;
            }
            if(ans>t){
                cout << min(pr0, k-ans+t-3600+1);
                return 0;
            }
            if(ans>mxans){
                mxans = ans;
                ansl = pr0;
            }
        }
    }
    if(mxans<=t){
        cout << -1;
    }
    else{
        cout << ansl;
    }
    return 0;
}







//    for(int i = 0; i < n; i++){
//        while(i<n && a[i].first<r && ans<=t){
//            ans+=min(r, a[i].second)-a[i].first;
//            i++;
//        }
//        if(i>0){
//            i--;
//        }
//        if(ans>t){
//            cout << min(l, a[i].second-3600+1-ans+t);
//            return 0;
//        }
//        if(ans>mxans){
//            mxans = ans;
//            ansl = min(l, a[i].second-3600+1-ans+t);
//        }
//        l = a[i+1].first;
//        r = l+3600;
//        ans = 0;
//    }
