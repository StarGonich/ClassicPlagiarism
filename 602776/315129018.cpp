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
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::vector<std::pair<int, int>> ans;

  int i = 0;
  while (i < n) {
    if (a[i] == i + 1) {
      ++i;
      continue;
    }
    int j = i + 1;
    while (j < n && a[j] == a[j - 1] + 1) {
      ++j;
    }

    ans.push_back(std::make_pair(i + 1, j - i));
    i = j;
  }

  if (ans.size() != 2) {
    std::cout << "-1\n";
  } else {
    for (auto x : ans) {
      std::cout << x.first << ' ' << x.second << '\n';
    }
  }
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
