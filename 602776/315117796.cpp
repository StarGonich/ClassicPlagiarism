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
#define endl '\n'
typedef long long ll;



using namespace std;
signed main()
{
	cin.sync_with_stdio(0); cout.sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> pos(n);
	vector<int> dist(n);
	for (int i = 0; i < n; i++)
		cin >> pos[i];
	for (int i = 0; i < n; i++)
		cin >> dist[i];
	int k; 
	cin >> k; k--;
	int lb = k - 1, rb = k + 1;
	int ld = pos[k] - dist[k], rd = pos[k] + dist[k];
	int cnt = 1;
	bool flag = false;
	while (cnt < n)
	{
		if (lb != -1 && pos[lb] >= ld)
		{
			cnt++;
			ld = min(ld, pos[lb] - dist[lb]);
			rd = max(rd, pos[lb] + dist[lb]);
			lb--;
		}
		else if (rb != n && pos[rb] <= rd)
		{
			cnt++;
			ld = min(ld, pos[rb] - dist[rb]);
			rd = max(rd, pos[rb] + dist[rb]);
			rb++;
		}
		else
			break;

	}
	cout << cnt;

	
}