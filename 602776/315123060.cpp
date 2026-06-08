#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  ll dp[n + 1][2][2]{};

  // n/take/cnt
  dp[0][0][0] = 1;

  for(int i = 1;i <= n;i++) {
    dp[i][1][0] = dp[i - 1][0][0];
    dp[i][0][0] = (dp[i - 1][1][0] + dp[i - 1][0][0]) % mod;

    dp[i][1][1] = (dp[i - 1][1][0] + dp[i - 1][0][1]) % mod;
    dp[i][0][1] = (dp[i - 1][0][1] + dp[i - 1][1][1]) % mod;
  }

  cout << (dp[n][0][1] + dp[n][1][1] + mod) % mod;
}