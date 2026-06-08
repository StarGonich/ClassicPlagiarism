#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include<stack>
#include<deque>
#include<queue>
#define ll long long
ll mod = 1e9 + 7;
using namespace std;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

ll binPow(ll x, ll y) {
	if (y == 0) {
		return 1;
	}

	if (y == 1) {
		return x;
	}

	if (y == 2) {
		return (x * x) % mod;
	}

	if (y % 2 == 0) {
		ll t = binPow(x, y / 2);
		return (t * t) % mod;
	}

	return (x * binPow(x, y - 1)) % mod;
}

void dfs(int x, vector<vector<int>>& G, vector<int>& Mark, set<int>& ans, vector<int>& pik) {
	Mark[x] = 1;
	int f = 1;
	for (int i = 0; i < G[x].size(); ++i) {
		if (Mark[G[x][i]] == 0 && pik[G[x][i]] < pik[x]) {
			dfs(G[x][i], G, Mark, ans, pik);
			f = 0;
		}
	}
	if (f) {
		ans.insert(x);
	}
}

void f(int v, vector<int>& x, vector<int>& d, vector<int>& Mark, int& ans) {
	++ans;
	Mark[v] = 1;
	int l = v - 1;
	int r = v + 1;
	while (l >= 0) {
		if (x[v] - d[v] > x[l]) {
			break;
		}
		if (Mark[l] == 0) {
			f(l, x, d, Mark, ans);
		}
		--l;
	}
	while (r < d.size()) {
		if (x[v] + d[v] < x[r]) {
			break;
		}
		if (Mark[r] == 0) {
			f(r, x, d, Mark, ans);
		}
		++r;
	}

}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<pair<int, int>>  arr;
	pair<int, int> p;
	int f = 0;
	int one_ind;
	for (int i = 0; i < n - 1; ++i) {
		if (f == 0) {
			if (v[i] == 1) {
				one_ind = arr.size();
			}
			p.first = v[i];
			p.second = v[i];
			f = 1;
		}
		if (v[i] == v[i+1] - 1) {
			p.second = v[i + 1];
		}
		else {
			arr.push_back(p);
			f = 0;
		}
	}
	if (f) {
		arr.push_back(p);
	}
	else {
		if (v[n - 1] == 1) {
			one_ind = arr.size();
		}
		arr.push_back({ v[n - 1],v[n - 1] });
	}
	if (arr.size() == 1 || arr.size()>=5) {
		cout << -1;
		return;
	}
	if (arr.size() == 2) {
		int ind1, ind2;
		ind1 = -1;
		ind2 = -1;
		for (int i = 0; i < n; ++i) {
			if (v[i] == arr[0].first) {
				ind1 = i + 1;
			}
			if (v[i] == arr[1].first) {
				ind2 = i + 1;
			}
			if (ind2 != -1 && ind1 != -1) {
				break;
			}
		}
		cout << ind1 << ' ' << arr[0].second - arr[0].first + 1 << '\n' << ind2 << ' ' << arr[1].second - arr[1].first + 1;
	}
	if (arr.size() == 3) {
		vector<pair<int,int>> arr1 = arr;
		sort(arr1.begin(), arr1.end());
		vector<pair<int, int>> arr2 = arr;
		vector<pair<int, int>> arr3 = arr;
		vector<pair<int, int>> arr4 = arr;
		swap(arr2[0], arr2[1]);
		swap(arr3[0], arr3[2]);
		swap(arr4[1], arr4[2]);
		int ind1, ind2;
		ind1 = -1;
		ind2 = -1;
		if (arr1 == arr2) {

			for (int i = 0; i < n; ++i) {
				if (v[i] == arr[0].first) {
					ind1 = i + 1;
				}
				if (v[i] == arr[1].first) {
					ind2 = i + 1;
				}
				if (ind2 != -1 && ind1 != -1) {
					break;
				}
			}
			cout << ind1 << ' ' << arr[0].second - arr[0].first + 1 << '\n' << ind2 << ' ' << arr[1].second - arr[1].first + 1;
		}
		else if (arr1 == arr3) {
			for (int i = 0; i < n; ++i) {
				if (v[i] == arr[0].first) {
					ind1 = i + 1;
				}
				if (v[i] == arr[2].first) {
					ind2 = i + 1;
				}
				if (ind2 != -1 && ind1 != -1) {
					break;
				}
			}
			cout << ind1 << ' ' << arr[0].second - arr[0].first + 1 << '\n' << ind2 << ' ' << arr[2].second - arr[2].first + 1;
		}
		else if(arr1==arr4){
			for (int i = 0; i < n; ++i) {
				if (v[i] == arr[1].first) {
					ind1 = i + 1;
				}
				if (v[i] == arr[2].first) {
					ind2 = i + 1;
				}
				if (ind2 != -1 && ind1 != -1) {
					break;
				}
			}
			cout << ind1 << ' ' << arr[1].second - arr[1].first + 1 << '\n' << ind2 << ' ' << arr[2].second - arr[2].first + 1;
		}
		else {
			cout << -1;
		}
	}
	if (arr.size() == 4) {
		vector<pair<int, int>> arr1 = arr;
		sort(arr1.begin(), arr1.end());
		vector<pair<int, int>> arr2 = arr;
		vector<pair<int, int>> arr3 = arr;
		vector<pair<int, int>> arr4 = arr;
		swap(arr2[0], arr2[2]);
		swap(arr3[1], arr3[3]);
		swap(arr4[1], arr4[2]);
		int ind1, ind2;
		ind1 = -1;
		ind2 = -1;
		if (arr1 == arr2) {

			for (int i = 0; i < n; ++i) {
				if (v[i] == arr[0].first) {
					ind1 = i + 1;
				}
				if (v[i] == arr[2].first) {
					ind2 = i + 1;
				}
				if (ind2 != -1 && ind1 != -1) {
					break;
				}
			}
			cout << ind1 << ' ' << arr[0].second - arr[0].first + 1 << '\n' << ind2 << ' ' << arr[2].second - arr[2].first + 1;
		}
		else if (arr1 == arr3) {
			for (int i = 0; i < n; ++i) {
				if (v[i] == arr[1].first) {
					ind1 = i + 1;
				}
				if (v[i] == arr[3].first) {
					ind2 = i + 1;
				}
				if (ind2 != -1 && ind1 != -1) {
					break;
				}
			}
			cout << ind1 << ' ' << arr[1].second - arr[1].first + 1 << '\n' << ind2 << ' ' << arr[3].second - arr[3].first + 1;
		}
		else if(arr1==arr4) {
			for (int i = 0; i < n; ++i) {
				if (v[i] == arr[1].first) {
					ind1 = i + 1;
				}
				if (v[i] == arr[2].first) {
					ind2 = i + 1;
				}
				if (ind2 != -1 && ind1 != -1) {
					break;
				}
			}
			cout << ind1 << ' ' << arr[1].second - arr[1].first + 1 << '\n' << ind2 << ' ' << arr[2].second - arr[2].first + 1;
		}
		else {
			cout << -1;
		}
	}
}




int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}
}