#include <bits/stdc++.h>

using namespace std;


signed main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<int> v(1000000001, 0);
    for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a]++;
		v[b]--;
    }
	int j = 0;
	long long s = v[0];
    for(int i = 1; i < v.size(); i++){
		v[i] += v[i - 1];
		s += v[i];
		if(i >= 3600) {
			s -= v[j];
			j++;
		}
		if(i >= 3600){
			if(s > t){
				cout << j;
				return 0;
			}
		}
    }
    cout << -1;
    return 0;
}
