#include <iostream>
#include <iterator>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

void boom(vector<int>& map, vector<int>& dist, int x, vector<bool>& dp) {
	if (dp[x] == true) { return; }
	dp[x] = true;
	int value = map[x] - dist[x];
	for (int i = x - 1; i >= 0; --i) {
		if (map[i] >= value) {
			boom(map, dist, i, dp);
		}
		else {
			break;
		}
	}

	value = map[x] + dist[x];
	for (int i = x + 1, n = map.size(); i < n; ++i) {
		if (map[i] <= value) {
			boom(map, dist, i, dp);
		}
		else {
			break;
		}
	} 
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> map(n); vector<int> dist(n); vector<bool> dp(n);
	for (int i = 0; i < n; ++i) {
		cin >> map[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> dist[i];
	}
	int k; cin >> k;
	int count = 0;
	boom(map, dist, k, dp);
	for (bool i : dp) {
		if (i == true) { count += 1; }
	}
	cout << count;
} 
