#include <bits/stdc++.h>

using namespace std;

#define int long long


void solve(){
    int n;
    cin >> n;
    int t;
    cin >> t;
    map <int, int> tot;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        tot[a]=1;
        tot[b]=-1;
    }
    int l=0, r=0, balance=0, cur=0;
    for(int r; r<3600; r++){
        balance+=tot[r];
        if(balance>0){
            cur++;
        }
    }
    if(cur>t){
        cout<<0;
        return;
    }
    bool flag = tot[0];
    for(r; r<1e8; r++){
        if(tot[l]==-1){
            flag = 0;
        }
        if(tot[l]==1){
            clag = 1;
        }
        if(flag){
            cur--;
        }
        if(tot[r]==-1){
            balance=0;
        }
        if(tot[r]==1){
            flag = 1;
            balance = 1;
        }
        cur += balance;
        l++;
        if(cur>=t){
            cout<<l+1;
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
