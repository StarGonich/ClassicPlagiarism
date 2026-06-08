#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  if(n == 1) {
    cout << "1 1\n";
    return 0;
  }

  if(n == 2) {
    cout << "3 4 5\n";
    return 0;
  }

  if(n == 3) {
    cout << "1 2 2 3\n";
    return 0;
  }

  if(n % 2 == 0) {
    for(int i = 0;i < n - 1;i++) {
      cout << "1 ";
    }
    cout << n / 2 - 1 << ' ' << n / 2 << '\n';
  } else {
    cout << 2 << ' ';
    for(int i = 1;i < n - 1;i++) {
      cout << "1 ";
    }
    cout << (n + 1) / 2 << ' ' << (n + 1) / 2 + 1 << '\n';
  }
}