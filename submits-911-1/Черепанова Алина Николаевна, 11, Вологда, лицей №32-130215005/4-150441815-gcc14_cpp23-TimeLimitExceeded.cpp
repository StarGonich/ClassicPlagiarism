#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main()
{
    int n, k;
    cin >> n >> k;
    int s = 1e18 + 1;
    int ans = -1;
	for(int p = n + 1; p <= n + k; p++){
		int d = n * p / (__gcd(n, p));
		if(d < s){
			s = d;
			ans = p;
		}
	}
	cout << ans;
    return 0;
}
