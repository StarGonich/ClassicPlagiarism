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
	int ll = k, rr = k;
	bool f1 = false, f2 = false;
	while (true) {
		f2 = false;
		f2 = false;
		bool y = false;
		while (ll >= 0) {
			if (x[ll] >= li && x[ll] <= ri) {
				y = true;
				r++;
				li = min(x[ll] - d[ll], li);
				ri = max(x[ll] + d[ll], ri);
				ll--;
			}
			else {
				if (not y)
					f1 = true;
				break;
				
			}
		}
		y = false;
		while (rr < n) {
			if (x[rr] >= li && x[rr] <= ri) {
				y = true;
				r++;
				li = min(x[rr] - d[rr], li);
				ri = max(x[rr] + d[rr], ri);
				rr++;
			}
			else {
				if (not y)
					f2 = true;
				break;
			}
		}
		if (!f1 && !f2)
			break;
	}
	



	//for (int i = 0; i <= n; i++) {
	//	if (k - i >= 0) {
	//		if (x[k - i] >= li && x[k - i] <= ri) {
	//			r++;
	//			li = min(x[k - i] - d[k - i], li);
	//			ri = max(x[k - i] + d[k - i], ri);
	//		}
	//	}
	//	if (k + i < n) {
	//		if (x[k + i] >= li && x[k + i] <= ri) {
	//			r++;
	//			li = min(x[k + i] - d[k + i], li);
	//			ri = max(x[k + i] + d[k + i], ri);
	//	}
	//	
	//		
	//	
	//}

			
		
	/*}*/
	cout << r - 1;

	

	return 0;
}