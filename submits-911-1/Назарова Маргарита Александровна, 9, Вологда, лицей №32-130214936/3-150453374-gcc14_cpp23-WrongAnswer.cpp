#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using ll =long long;

int main()
{
    int n; ll t;
    cin >> n >> t;
    vector <pair <ll, ll>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    ll l = 0, r = 3600;
    int ansl = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        while(i<n && a[i].first<r && ans<=t){
            ans+=min(r, a[i].second)-a[i].first;
            i++;
        }
        i--;
        if(ans>t){
            cout << min(l, a[i].second-3600+1-ans+t);
            return 0;
        }
        l = r+1;
        r+=3600;

    }
    if(ans<=t){
        cout << -1;
    }
    else{
        cout << l;
    }
    return 0;
}
