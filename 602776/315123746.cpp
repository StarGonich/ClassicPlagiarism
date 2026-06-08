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
	int money = 210;
	int loses = 0;
	int m, stav;
	while (true)
	{
		if (loses == 3)
			stav = money;
		else
			stav = 1;
		cout << stav << "R" << endl;
		flush(cout);
		cin >> m;
		if (m == 0)
		{
			money -= stav;
			loses++;
		}
		else if (m == 1)
		{
			money += stav;
			loses = 0;
			if (money >= 1000)
				break;
		}
		else
		{
			break;
		}
	}
}