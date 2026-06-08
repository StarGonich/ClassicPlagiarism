#include <bits/stdc++.h>

using namespace std;


signed main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    int T = 0;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[i] = {a, b};
		T = max(T, b);
    }
    sort(v.begin(), v.end());
	if(T > 1000000){
		for(int i = 0; i < n; i++){
		int f = v[i].first + 3600;
		int j = i, s = 0;
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
	vector<int> a(1e6 + 1, 0);
    for(int i = 0; i < n; i++){
		a[v[i].first]++;
		a[v[i].second]--;
    }
	int j = 0;
	long long s = a[0];
    for(int i = 1; i < v.size(); i++){
		a[i] += a[i - 1];
		s += a[i];
		if(i >= 3600) {
			s -= a[j];
			j++;
		}
		if(s > t){
			cout << j;
			return 0;
		}
    }
	cout << -1;
    return 0;
}
