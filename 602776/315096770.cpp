#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;

  // int slow = 0;
  // for(int i = 1;i <= n;i++) {
  //   int cnt = 0;
  //   cnt += i % 4 == 0;
  //   cnt += i % 5 == 0;
  //   cnt += i % 6 == 0;
  //   slow += cnt == 1;
  // }
  // cout << slow << ' ';
  
  cout << n / 4 + n / 5 + n / 6 - 2 * (n / 20) - 2 * (n / 12) - 2 * (n / 30) + 3 * (n / 60) << '\n';
}