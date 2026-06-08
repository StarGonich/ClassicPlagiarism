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
	vector<ll> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		ar[i]--;
	}
	ll left = 0;
	while (left < n && ar[left] == left) {
		left++;
	}
	ll right = n - 1;
	while (right >= 0 && ar[right] == right) {
		right--;
	}
	if (right == -1) {
		cout << "-1";
		return;
	}
	ll left2;
	for (int i = left; i < right; i++) {
		if (ar[i] == right) {
			left2 = i;
			break;
		}
	}
	ll right2 = left2 + 1;
	for (int i = right; i > left; i--) {
		if (ar[i] == left) {
			right2 = i;
			break;
		}
	}
	if (left2 >= right2) {
		cout << "-1";
		return;
	}
	vector<ll> mb_ans;
	for (int i = 0; i < left; i++) {
		mb_ans.push_back(ar[i]);
	}
	for (int i = right2; i <= right; i++) {
		mb_ans.push_back(ar[i]);
	}
	for (int i = left; i <= left2; i++) {
		mb_ans.push_back(ar[i]);
	}
	for (int i = right + 1; i < n; i++) {
		mb_ans.push_back(ar[i]);
	}
	for (int i = 0; i < n; i++) {
		if (mb_ans[i] != i) {
			cout << "-1";
			return;
		}
	}
	cout << left + 1 << " " << left2 - left + 1 << endl;
	cout << right2 + 1 << " " << right - right2 + 1 << endl;
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