#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int l = 0, cur = 0;
    bool flag = false;
    for (int r = 0; r < n; r++) {
        cur += a[r].second - a[r].first;
        while (a[r].first - a[l].second >= 3600 && l<r) {
            cur -= a[l].second - a[l].first;
            l++;
        }
        if(l>0){
            cur+=max((int)0, a[l-1].second-(a[r].first - 3600));
        }
        if (cur > t) {
            cout << a[r].second-3600+1-(cur - a[r].second+a[r].first);
            return;
        }
    }
    cout << -1 << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    //cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
