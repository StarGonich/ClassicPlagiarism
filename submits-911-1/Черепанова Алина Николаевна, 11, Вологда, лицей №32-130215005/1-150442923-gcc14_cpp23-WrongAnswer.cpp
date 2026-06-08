#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main()
{
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int a = h1 * 60 + m1;
    int b = h2 * 60 + m2;
    int k = 0;
    for(int i = a; i <= b; i++){
		int h = i / 60, m = i % 60;
		vector<int> s = {(h / 10), (h % 10), (m / 10), (m % 10)};
		if(h == m) k++;
		else if(s[0] == s[3] && s[1] == s[2]) k++;
		else if(h == 1 && m == 23 || h == 12 && m == 34 || h == 23 && m == 45) k++;
    }
    cout << k;
    return 0;
}
