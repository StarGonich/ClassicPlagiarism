#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;
    if (n==1){
        cout<<1;
        return;
    }
    if (n==2){
        cout<<-1;
        return;
    }
    n -= 3;
    vector <int> ans = {1, 2, 3};
    ans.reserve(30);
    int total = 6;
    while(n--){
        ans.push_back(total);
        total*=2;
    }
    cout<<total<<endl;
    for(auto i: ans){
        cout << i << ' ';
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
