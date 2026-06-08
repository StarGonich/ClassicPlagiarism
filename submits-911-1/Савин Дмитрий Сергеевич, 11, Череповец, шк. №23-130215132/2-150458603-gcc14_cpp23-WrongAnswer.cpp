#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    switch(n) {
    case 1: {
      std::cout << 1 << '\n' << 1 << std::endl;
      break;
    }
    case 3: {
      std::cout << 6 << '\n' << 3 << ' ' << 2 << ' ' << 1 << std::endl;
      break;
    }
    default: {
      std::cout << -1 << std::endl;
      break;
    }
    }
    return 0;
}