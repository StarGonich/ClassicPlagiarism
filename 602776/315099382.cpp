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
  ld a, b, p;
  ld c, d, q;

  std::cin >> a >> b >> p >> c >> d >> q;

  ld det = c * b - a * d;
  if (det == 0) {
    if (p == q) {
      std::cout << "Ambiguity" << '\n';
    } else {
      std::cout << "Contradiction" << '\n';
    }
  } else {
    ld x = (q * b - p * d) / det;
    ld y = (c * p - a * q) / det;

    if (x <= 0 || y <= 0) {
      std::cout << "Not positive" << '\n';
    } else {
      std::cout << "Success" << '\n';
      std::cout << x * 100 << ' ' << y * 100 << '\n';
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
