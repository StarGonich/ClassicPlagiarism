#include <bits/stdc++.h>
#define int long long
using namespace std;
int pr=1e9+7;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n+7),pref(n+7);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for (int i=4;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%pr;
    }
    int ans=0;
    for (int i=0;i<n-1;i++){
        ans=(ans+dp[i]*dp[n-i-2])%pr;
    }
    cout<<ans<<endl;
    return 0;
}
