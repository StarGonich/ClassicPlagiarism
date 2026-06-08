#include <bits/stdc++.h>

using namespace std;


signed main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<long long> v(1e6 + 2, 0);
    vector<long long> p(1e6 + 2, 0);
    for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a]++;
		v[b]--;
    }

    for(int i = 1; i < p.size(); i++){
		v[i] += v[i - 1];
		p[i] += p[i - 1] + v[i];
		if(i >= 3600){
			if(p[i] - p[i - 3600] > t){
				cout << i - 3600 + 1;
				return 0;
			}
		}
    }
    cout << -1;
    return 0;
}
