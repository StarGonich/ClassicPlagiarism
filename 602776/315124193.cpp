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

ll f[1001][1001];
std::vector<std::vector<ll>> g;
std::vector<ll> c;

const ll inf = 100000000;

struct Trio {
  ll price;
  ll minToBuy;
  ll x;

  Trio* prev = nullptr;

  bool operator<(Trio that) const {
    return std::make_pair(price, c[minToBuy]) < std::make_pair(that.price, c[that.minToBuy]);
  }
};

struct TrioComp {
  bool operator()(const Trio* l, const Trio* r) const {
    return *l < *r;
  }
};

void solve() {
  ll n, m;
  std::cin >> n >> m;

  g.resize(n + 1);
  c.resize(n + 1);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i != j) {
        f[i][j] = inf;
      }
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    std::cin >> c[i];
  }

  for (int i = 0; i < m; ++i) {
    ll u, w, dist;
    std::cin >> u >> w >> dist;
    f[u][w] = std::min(f[u][w], dist);
    f[w][u] = std::min(f[w][u], dist);
    g[u].push_back(w);
    g[w].push_back(u);
  }

  std::set<Trio*, TrioComp> q;
  auto start = new Trio{0, 1, 1};
  q.insert(start);

  std::vector<ll> price(n + 1, inf);
  price[1] = 0;
  std::vector<std::vector<ll>> path(n + 1);

  std::vector<int> ansPath;
  std::vector<int> used(n + 1);

  int cnt = 0;

  bool stop = false;
  while (!q.empty() && !stop) {
    auto topPtr = *q.begin();
    auto top = *topPtr;
    q.erase(q.begin());

    if (++used[top.x] == 20) {
      stop = true;
      break;
    }

    if (top.x == n) {
      auto iter = topPtr;
      while (iter != nullptr) {
        ansPath.push_back(iter->x);
        iter = iter->prev;
      }

      if (ansPath.back() != 1) {
        std::cout << "-1\n";
        break;
      }

      //std::cout << "res: " << top.price << std::endl;
      std::cout << top.price << std::endl;

      std::vector<ll> toBy(n + 1);

      std::reverse(ansPath.begin(), ansPath.end());
      int i = 0;
      while (i < ansPath.size()) {
        int j = i + 1;
        while (j < ansPath.size() && c[ansPath[i]] <= c[ansPath[j]]) {
          toBy[ansPath[i]] += f[ansPath[j]][ansPath[j - 1]];
          j++;
        }
        if (j < ansPath.size()) {
          toBy[ansPath[i]] += f[ansPath[j]][ansPath[j - 1]];
        }
        i = j;
      }

      std::set<ll> seen;

      std::cout << ansPath.size() << '\n';
      for (auto x : ansPath) {
        std::cout << x << " " << (seen.find(x) != seen.end() ? 0 : toBy[x]) << std::endl;
        seen.insert(x);
      }

      break;
    }
    //std::cout << "now at: " << top.x << ' ' << top.price << std::endl;

    for (ll adj : g[top.x]) {

      ll toAdj = top.price + f[top.x][adj] * c[top.minToBuy];
      bool put = false;

      //if (adj != n && minCost[adj] > minCost[top.second]) {
      //  path[adj].push_back(top.second);
      //  q.insert({ toAdj, adj });
      //  minCost[adj] = std::min(minCost[adj], minCost[top.second]);
      //  put = true;
      //}

      //if (price[adj] > toAdj) {
      //price[adj] = toAdj;
      path[adj].push_back(top.x);
      ll nxtMin = c[adj] < c[top.minToBuy] ? adj : top.minToBuy;
      auto nxt = new Trio{ toAdj, nxtMin, adj };
      nxt->prev = topPtr;
      q.insert(nxt);
      //minCost[adj] = std::min(minCost[adj], minCost[top.second]);
      put = true;
      //}

      //if (adj == n) {
      //  found = true;
      //  break;
      //}
    }
  }

  /*std::cout << "done" << std::endl;
  for (int i = 1; i <= n; ++i) {
    std::cout << i << ": ";
    for (auto x : path[i]) {
      std::cout << x <<  " ";
    }
    std::cout << std::endl;
  }*/

  if (stop) {
    std::cout << "-1\n";
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
