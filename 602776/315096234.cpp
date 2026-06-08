#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>

#define all(x) x.begin(), x.end()
typedef long long ll;



using namespace std;
signed main()
{
	cin.sync_with_stdio(0); cout.sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 4 == 0 && i % 5 != 0 && i % 6 != 0)
			cnt++;
		else if (i % 4 != 0 && i % 5 == 0 && i % 6 != 0)
			cnt++;
		else if (i % 4 != 0 && i % 5 != 0 && i % 6 == 0)
			cnt++;
	}
	cout << cnt;
}