#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Node{
    int a;
    int type;
};

void solve(){
    int n, p;
    cin>>n>>p;
    p=n+p;
    int dub=n;
    for(int i=2; i*i<=n; i++){
        while(dub%i==0){
            dub/=i;
        }
    }
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            if(n/i*(i+1)<=p){
                cout<<n/i*(i+1);
                return;
            }
        }
    }
    if(n/dub*(dub+1)<=p){
        cout<<n/dub*(dub+1);
        return;
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
