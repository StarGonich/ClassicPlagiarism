#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n;
	
	vector<int> x(n), d(n), got(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	
	cin >> k;
	k--;
	got[k] = 1;
	
	vector<int> st;
	st.push_back(k);
	
	while (st.size() > 0) {
		int cur = st.back();
		st.pop_back();
		
		int l = -1, r = cur;
		while (l < r - 1) {
			int m = (r + l)/2;
			if (x[m] < x[cur] - d[cur]) {
				l = m;
			} else {
				r = m;
			}
		}
		
		for (int i = r; i < cur; i++) {
			if (got[i] == 1) break;
			got[i] = 1;
			st.push_back(i);
		}
		
		
		l = cur, r = n;
		while (l < r - 1) {
			int m = (r + l)/2;
			if (x[m] <= x[cur] + d[cur]) {
				l = m;
			} else {
				r = m;
			}
		}

	//	cout << "right: " << l << " " << r << " " << cur + 1 << endl;
		for (int i = l; i >= cur; i--) {
			if (got[i] == 1) break;
			got[i] = 1;
			st.push_back(i);
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (got[i] == 1) {
		//	cout << i + 1 << " ";
			ans++;
		}
	}
	
	cout << ans;
	
	return 0;
}