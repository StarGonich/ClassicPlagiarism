#include <bits/stdc++.h>

using namespace std;


signed main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<pair<long long, long long>> v(n);
    for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[i] = {a, b};
    }
	for(int i = 0; i < n; i++){
		long long f = v[i].first + 3600;
		int j = i;
		long long s = 0;
		while(j < n && v[j].first <= f){
			s += min(f, v[j].second) - v[j].first + 1;
			j++;
		}
		if(s > t){
			cout << v[i].first;
			return 0;
		}
	}
	for(int i = n - 1; i >= 0; i++){
		long long f = v[i].second - 3600;
		int j = i;
		long long s = 0;
		while(j > 0 && v[j].second >= f){
			s += v[j].second - max(f, v[j].first)  + 1;
			j++;
		}
		if(s > t){
			cout << f;
			return 0;
		}
	}
	cout << -1;
    return 0;
}
