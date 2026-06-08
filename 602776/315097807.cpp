#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>

typedef long long ll;

void solve() {
  ll n;
  std::cin >> n;

  std::vector<int> cnt(200);
  for (int x = 4; x <= 6; ++x) {
    for (int i = 1; i <= 120; ++i) {
      if (i % x == 0) {
        ++cnt[i];
      }
    }
  }

  int perBlock = 0;
  for (int i = 1; i <= 120; ++i) {
    if (cnt[i] == 1) {
      perBlock++;
    }
  }

  ll ans = perBlock * (n / 120);
  ll rem = n % 120;
  for (int i = 1; i <= rem; ++i) {
    if (cnt[i] == 1) {
      ++ans;
    }
  }

  std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);

    int t = 1;
    //std::cin >> t;
    for (; t > 0; --t) {
      solve();
    }
}
