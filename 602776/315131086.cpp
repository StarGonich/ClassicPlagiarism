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
	vector<int> ch(n);
	
	for (int i = 0; i < n; i++)
		cin >> ch[i];
	vector<pair<int, int>> skip;
	int start = 0, len = 0;
	for (int i = 0; i < n; i++)
	{
		if (ch[i] != i + 1)
		{
			if (len == 0)
			{
				start = i;
				len = 1;
			}
			else
				len++;
		}
		else
		{
			if (len != 0)
			{
				skip.emplace_back(start, start + len - 1);
				len = 0;
			}
		}
	}
	if (len != 0)
	{
		skip.emplace_back(start, start + len - 1);
		len = 0;
	}
	if (skip.size() > 2 || skip.size() == 0)
	{
		cout << -1;
		return 0;
	}

	if (skip.size() == 1)
	{
		auto k = skip[0];
		int jump = 0;
		for (int i = 0; i < k.second - k.first; i++)
		{
			if (ch[k.first + i] > ch[k.first + i + 1])
			{
				if (jump != 0)
				{
					cout << -1;
					return 0;
				}
				jump = k.first + i + 1;
			}
		}
		vector<int> itog;
		int i = 0;
		while (itog.size() < n)
		{
			if (i < k.first || i > k.second)
			{
				i++;
				itog.push_back(i);
			}
			else
			{
				i = k.second + 1;
				for (int j = jump; j <= k.second; j++)
				{
					itog.push_back(ch[j]);
				}
				for (int j = k.first; j < jump; j++)
				{
					itog.push_back(ch[j]);
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (itog[i] != i + 1)
			{
				cout << -1;
				return 0;
			}
		}
		cout << k.first + 1 << " " << jump - k.first << endl;
		cout << jump + 1 << " " << k.second - jump + 1 << endl;
	}
	else
	{
		auto a = skip[0];
		auto b = skip[1];
		for (int i = a.first; i < a.second; i++)
		{
			if (ch[i] > ch[i + 1])
			{
				cout << -1;
				return 0;
			}
		}
		for (int i = b.first; i < b.second; i++)
		{
			if (ch[i] > ch[i + 1])
			{
				cout << -1;
				return 0;
			}
		}
		vector<int> itog;
		int i = 1;
		while (itog.size() < n)
		{
			if (i < ch[b.first])
			{
				itog.push_back(i);
				i++;
			}
			else if (i < ch[b.second])
			{
				i = ch[b.second] + 1;
				for (int i = b.first; i <= b.second; i++)
				{
					itog.push_back(ch[i]);
				}
			}
			else if (i < ch[a.first])
			{

				itog.push_back(i);
				i++;
			}
			else if (i < ch[a.second])
			{
				i = ch[a.second] + 1;
				for (int i = a.first; i <= a.second; i++)
				{
					itog.push_back(ch[i]);
				}
			}
			else
			{

				itog.push_back(i);
				i++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (itog[i] != i + 1)
			{
				cout << -1;
				return 0;
			}
		}
		cout << a.first + 1 << " " << a.second - a.first + 1 << endl;
		cout << b.first + 1 << " " << b.second - b.first + 1 << endl;
	}
}