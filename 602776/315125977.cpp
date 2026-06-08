#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  
  vector<int> p(n);
  for(int& e : p)
    cin >> e, e--;;
  
  vector<int> ip(n);
  for(int i = 0;i < n;i++)
    ip[p[i]] = i;
  
  int wpos = -1;
  for(int i = 0;i < n;i++) {
    if(p[i] != i) {
      wpos = i;
      break;
    }
  }

  if(wpos == -1) {
    cout << "-1\n";
    return 0;
  }

  int npos = ip[wpos];

  int l1 = wpos;
  int l2 = npos + 1;
  
  while(l1 < npos) {
    if(p[l1] == l1) {
      break;
    }
    l1++;
  }

  while(l2 < n) {
    if(p[l2] != p[l2 - 1] + 1) {
      break;
    }
    l2++;
  }

  vector<int> p1(p.begin(), p.begin() + wpos);
  vector<int> p2(p.begin() + npos, p.begin() + l2);
  vector<int> p3(p.begin() + wpos, p.begin() + l1);
  vector<int> p4(p.begin() + l2, p.end());

  vector<int> np;
  for(int i = 0;i < p1.size();i++) {
    np.push_back(p1[i]);
  }
  for(int i = 0;i < p2.size();i++) {
    np.push_back(p2[i]);
  }
  for(int i = 0;i < p3.size();i++) {
    np.push_back(p3[i]);
  }
  for(int i = 0;i < p4.size();i++) {
    np.push_back(p4[i]);
  }

  if(is_sorted(np.begin(), np.end())) {
    cout << wpos + 1 << ' ' << l1 - wpos << '\n';
    cout << npos + 1 << ' ' << l2 - npos << '\n';
  } else {
    cout << "-1\n";
  }
}