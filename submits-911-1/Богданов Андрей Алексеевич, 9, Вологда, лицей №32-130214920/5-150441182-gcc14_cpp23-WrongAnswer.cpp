#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int k;
    int n, m;
    cin>>k;
    cin>>n>>m;
    vector<pair<int, int>> a;
    for(int l=1; l<=k; l++){
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x;
                cin>>x;
                ans+=x;
            }
        }
        a.push_back({ans, l});
    }
    sort(a.rbegin(), a.rend());
    for(auto u: a){
        cout<<u.second<<' ';
    }
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
