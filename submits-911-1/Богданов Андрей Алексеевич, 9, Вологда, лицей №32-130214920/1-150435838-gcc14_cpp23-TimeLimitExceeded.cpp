#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n, m, a, b, ans=0;
    cin >> n >> m >> a >> b;
    while(n != a || m != b){
        if(n == m || n%10*10+n/10 == m || (n/10==n%10+1 && n%10==m/10+1 && m/10==m%10+1)){
            ans++;
        }
        m++;
        if(m>60){
            n++;
            m%=60;
        }
    }
    cout << ans;
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
