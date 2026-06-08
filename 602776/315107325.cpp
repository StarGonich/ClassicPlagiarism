#include <bits/stdc++.h>

using namespace std;

int p[100005];

int mod = 1e9 + 7;
int bp(int a, int b)
{
    if(b == 0)
        return 1;
    if(b & 1)
        return 1ll*a*bp(a, b-1) % mod;
    else
        return 1ll * bp(1ll * a * a % mod, b / 2);
}

int dp[1000006];
int main() {
    int n;
    
    cin >> n;
    /*for(int i = 0; i < n; i ++)
    {
        cin >> p[i];
    }*/

    dp[1] = 2;
    dp[2] = 3;
    for(int i = 3; i <= n; i ++)
    {
        dp[i] = (dp[i - 2] + dp[i-1]) % mod;
    }
    
    int ans = 0;
    for(int i = 1; i <= n-1; i ++)
    {
        ans = (ans + 1ll*(i - 2 >= 1 ? dp[i-2] : 1) * (n - i - 1 - 1 >= 1 ? dp[n - i - 1 - 1] : 1)) % mod;
    }
    
    cout << ans;

    return 0;
}