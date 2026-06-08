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
	k--;
	int li = x[k], ri = x[k];
	for (int i = 0; i <= n / 2; i++) {
		if (k - i >= 0) {
			if (x[k - i] >= li && x[k - i] <= ri) {
				r++;
				li = min(x[k - i] - d[k - i], li);
				ri = max(x[k - i] + d[k - i], ri);
			}
		}
		if (k + 1 < n) {
			if (x[k + i] >= li && x[k + i] <= ri) {
				r++;
				li = min(x[k + i] - d[k + i], li);
				ri = max(x[k + i] + d[k + i], ri);
		}
		
			
		
	}

			
		
	}
	cout << r - 1;

	

	return 0;
}