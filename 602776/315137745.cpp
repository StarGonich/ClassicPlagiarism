#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <ios>
#include <iomanip>
#include <cmath>

#define int long long
#define ll long long

using namespace std;

void solve() {
	int n; cin >> n;

	int sum = 0;
	int cnt = 0;
	vector<int> nums;
	for (int start = 3; start < 100; start++) {
		for (int i = start; i <= 1000000; i++) {
			if ((int)sqrt(sum + i * i) * (int)sqrt(sum + i * i) == sum + i * i) {
				sum += i * i;
				nums.push_back(i);
				cnt++;
			}
			if (cnt == n) {
				for (int i : nums) {
					cout << i << " ";
				}
				cout << (int)sqrt(sum) << "\n";
				return;
			}
		}
	}

	cout << -1 << "\n";
}

signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}
