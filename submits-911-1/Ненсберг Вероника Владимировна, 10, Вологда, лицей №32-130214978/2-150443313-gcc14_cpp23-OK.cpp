#include <bits/stdc++.h>

using namespace std;

int main() {
    int magic_ans = 1680;
    int k;
    cin >> k;
    if (k == 2) {
        cout << -1;
        return 0;
    }
    vector<int> d;
    for (int j = 1; j * j <= magic_ans; j++) {
        if (magic_ans % j == 0) {
            d.push_back(j);
            d.push_back(magic_ans / j);
        }
    }
    sort(d.begin(), d.end());
    vector<vector<int>> dp(magic_ans + 1, vector<int> (31, -1));
    dp[0][0] = 0;
    for (int i = 0; i < d.size(); i++) {
        for (int sum = magic_ans - d[i]; sum >= 0; sum--) {
            for (int cnt = 29; cnt >= 0; cnt--) {
                if (dp[sum][cnt] == -1 || dp[sum + d[i]][cnt + 1] != -1) {
                    continue;
                }
                dp[sum + d[i]][cnt + 1] = sum;
            }
        }
    }
    cout << magic_ans << '\n';
    int cur = magic_ans;
    while (k != 0) {
        cout << cur - dp[cur][k] << " ";
        cur = dp[cur][k];
        k--;
    }
    return 0;
}
