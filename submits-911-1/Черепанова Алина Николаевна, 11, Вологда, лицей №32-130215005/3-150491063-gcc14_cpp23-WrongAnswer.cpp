#include <bits/stdc++.h>

using namespace std;


signed main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[i] = {a, b};
    }
    sort(v.begin(), v.end());

	for(int i = 0; i < n; i++){
		int f = v[i].first + 3600;
		int j = i; 
		long long s = 0;
		while(v[j].first <= f){
			s += min(f, v[j].second) - v[j].first + 1;
			j++;
		}
		if(s > t){
			cout << v[i].first;
			return 0;
		}
	}
	cout << -1;
    return 0;
}
