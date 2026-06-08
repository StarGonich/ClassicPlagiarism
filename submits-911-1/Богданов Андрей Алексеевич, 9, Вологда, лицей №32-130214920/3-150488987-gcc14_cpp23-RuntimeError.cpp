#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector <char> tot(1e8, 0);
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        for(int i=a; i<=b; i++){
            tot[i]=1;
        }
    }
    int cur=0;
    for(int i=0; i<3600; i++){
        cur+=tot[i];
    }
    int l=0, r=3600;
    if(cur>t){
        cout<<l;
        return;
    }
    for(r; r<1e9; r++){
        cur+=tot[r];
        cur-=tot[l];
        if(cur>t){
            cout<<l;
            return;
        }
    }
    cout<<-1;
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
