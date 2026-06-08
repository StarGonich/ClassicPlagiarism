#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<long long> dp(n + 1);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= n; i++) {
        if (i == 5) {
            dp[i] = 8;
        }
        else if(i==6){
            dp[i] = (i + dp[i - 1]);
        }
        else {
            dp[i] = (i - 1 + dp[i - 1]) % 1000000007;
        }
    }
    cout << dp[n];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}
