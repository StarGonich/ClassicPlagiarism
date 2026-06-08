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
	int n;
	cin >> n;

	for (int i = 1; i < 1000000; i++) {
		int sum = 0;
		for (int j = i; j < i + n; j++) {
			sum += j * j;
		}

		if ((int)sqrt(sum) * (int)sqrt(sum) == sum) {
			for (int j = i; j < i + n; j++) {
				cout << j << " ";
			}
			cout << (int)sqrt(sum);
			return;
		}
	}

	cout << -1;
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
