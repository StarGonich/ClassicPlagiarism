#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for(int& e : a)
    cin >> e;
  
  vector<int> d(n);
  for(int& e : d) 
    cin >> e;
  int k = 0;
  cin >> k;

  k--;

  int l = k;
  int r = k;

  vector<bool> denoted(n);
  int max_r = a[l] + d[l];
  int max_l = a[l] - d[l];
  while(true) {
    bool need_continue = false;
    if(l < n && a[l] <= max_r) {
      need_continue = true;
      denoted[l] = 1;
      max_r = max(max_r, a[l] + d[l]);
      max_l = min(max_l, a[l] - d[l]);
      l++;
    } else if(r >= 0 && a[r] >= max_l) {
      need_continue = true;
      denoted[r] = 1;
      max_l = min(max_l, a[r] - d[r]);
      max_r = max(max_r, a[r] + d[r]);
      r--;
    }

    if(!need_continue) break;
  }

  int s = 0;
  for(auto e : denoted)
    s += e;
  cout << s << '\n';
}