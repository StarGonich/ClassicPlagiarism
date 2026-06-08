#include <iostream>
#include <string> 
#include <vector> 
#include <algorithm> 
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <cstdlib>
using namespace std;



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k, r = 0;
	cin >> n;
	vector<int> x(n), d(n);
	
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n; i++)
		cin >> d[i];
	cin >> k;
	int li = x[k - 1], ri = x[k - 1];
	for (int i = k - 1; i >= 0; i--) {
		if (x[i] >= li && x[i] <= ri)
			r++;
		li = min(max(0, x[i] - d[i]), li);
		ri = max(min(x[n - 1], x[i] + d[i]), ri);
	}
	for (int i = k - 1; i < n; i++) {
		if (x[i] >= li && x[i] <= ri)
			r++;
		li = min(max(0, x[i] - d[i]), li);
		ri = max(min(x[n - 1], x[i] + d[i]), ri);
	}
	cout << r - 1;

	

	return 0;
}