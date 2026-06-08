#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1;
        return 0;
    }
	if (n == 1) {
		cout << 1 << '\n' << 1;
		return 0;
	}
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(2);
    ans.push_back(3);
    int sum = 6;
    for (int i = 3; i < n; ++i) {
        ans.push_back(sum);
        sum *= 2;
    }
    cout << sum << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
