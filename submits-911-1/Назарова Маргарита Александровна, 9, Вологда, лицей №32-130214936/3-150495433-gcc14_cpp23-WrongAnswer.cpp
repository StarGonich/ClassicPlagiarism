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
    ll pr = 0;
    for(auto [k, v]:m){
        if(v==0){
            if(k-pr0>h){
                if(ans>t){
                    cout << min(pr0, k-ans+t-3600+1);
                    return 0;
                }
                if(ans>mxans){
                    mxans = ans;
                    ansl = min(pr0, k-ans+t-3600+1);
                }
                ans = 0;
                pr0 = k;
            }
            pr = k;
        }
        else{
            if(k-pr0>h){
                pr0 = pr;
                ans = pr1-k+3600;
                if(ans<0){
                    ans = 0;
                }
            }
            ans+=k-pr;
            if(ans>t){
                cout << min(pr0, k-ans+t-3600+1);
                return 0;
            }
            if(ans>mxans){
                mxans = ans;
                ansl = min(pr0, k-ans+t-3600+1);
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

