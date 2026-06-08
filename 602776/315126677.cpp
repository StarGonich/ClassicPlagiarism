#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef long double ld;

void solve() {
  ll n;
  std::cin >> n;

  std::vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> x[i];
  }

  std::vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> d[i];
  }

  ll k;
  std::cin >> k;
  --k;

  int cnt = 1;

  int lBlow = x[k] - d[k];
  int rBlow = x[k] + d[k];
  ll l = k - 1;
  ll r = k + 1;

  while (l >= 0 && x[l] >= lBlow || r < n && x[r] <= rBlow) {
    if (l >= 0 && x[l] >= lBlow) {
      ++cnt;
      lBlow = std::min(lBlow, x[l] - d[l]);
      rBlow = std::max(rBlow, x[l] + d[l]);
      --l;
      continue;
    }
    if (r < n && x[r] <= rBlow) {
      ++cnt;
      lBlow = std::min(lBlow, x[r] - d[r]);
      rBlow = std::max(rBlow, x[r] + d[r]);
      ++r;
      continue;
    }
  }

  std::cout << cnt << '\n';
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

/*
4 3
1000 100 1 10
1 2 1
2 3 1
2 4 10
*/
