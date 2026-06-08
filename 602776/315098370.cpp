#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
using ll = long long;

int c = 210;

int bet(int x) {
  cout << x << ' ' << "R" << endl;
  c -= x;
  cin >> x;
  return x;  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  
  while(c < 1000) {
    int t = bet(10);
    if(t == 1) {
      c += 20;
      continue;
    }

    t = bet(20);
    if(t == 1) {
      c += 40;
      continue;
    }

    t = bet(30);
    if(t == 1) {
      c += 60;
      continue;
    }

    int pc = c;
    t = bet(c);
    if(t == 1) {
      c += 2 * pc;
      continue;
    } else {
      assert(false);
    }
  }
}