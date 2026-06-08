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
	vector<char> boom(n);
	int lb = k, rb = k;
	int ld = pos[k] - dist[k], rd = pos[k] + dist[k];
	int cnt = 1;
	while (cnt < n)
	{
		if (!boom[lb])
		{
			if (lb != rb)
				boom[lb] = 1;
			if (lb != 0)
			{
				if (pos[lb - 1] >= ld)
				{
					lb--;
					ld = min(ld, pos[lb] - dist[lb]);
					rd = max(rd, pos[lb] + dist[lb]);
					cnt++;
				}
			}
		}
		else if (!boom[rb])
		{
			boom[rb] = 1;
			if (rb != n - 1)
			{
				if (pos[rb + 1] <= rd)
				{
					rb++;
					ld = min(ld, pos[rb] - dist[rb]);
					rd = max(rd, pos[rb] + dist[rb]);
					cnt++;
				}
			}
		}
		else
			break;

	}
	cout << cnt;

	
}