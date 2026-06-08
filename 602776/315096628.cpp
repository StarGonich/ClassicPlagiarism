#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <memory>
#include <stack>
using namespace std;
using ll = long long;
using ld = long double;
#define debug(x) std::cerr << __FUNCTION__ << ":" << __LINE__ << " " << #x << " = " << x << '\n';
const ll INF = 4e18;
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
void solve(){
	ll n;
	cin >> n;
	//cout << n / 4 + n / 5 + n / 6 << endl;
	cout << n / 4 + n / 5 + n / 6 - 2 * (n / 20) - 2 * (n / 30) - 2 * (n / 12) + 3 * (n / 60);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1;
	//cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}