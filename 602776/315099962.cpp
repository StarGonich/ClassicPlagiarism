#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
using ll = long long;

int c = 210;
int cnt = 0;

int bet(int x) {
  cnt++;
  cout << x << ' ' << "R" << endl;
  c -= x;
  cin >> x;
  assert(x != -1);
  return x;  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while(c < 1000) {
    int b = c / 15;
    int t = bet(b);
    if(t == 1) {
      c += 2 * b;
      continue;
    }

    t = bet(2 * b);
    if(t == 1) {
      c += 4 * b;
      continue;
    }

    t = bet(4 * b);
    if(t == 1) {
      c += 8 * b;
      continue;
    }

    int pc = 8 * b;
    t = bet(pc);
    if(t == 1) {
      c += 2 * pc;
      continue;
    } else {
      assert(false);
    }
  }
}