#include <bits/stdc++.h>

using namespace std;


signed main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		if(b - a + 1> t){
			cout << a;
			return 0;
		}
    }
	cout << -1;
    return 0;
}
