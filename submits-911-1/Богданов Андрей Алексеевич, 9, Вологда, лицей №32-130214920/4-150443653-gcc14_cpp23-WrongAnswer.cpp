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
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            n/=i;
            n*=i+1;
            cout<<n;
        }
    }
    cout<<n*2;
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
