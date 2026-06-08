#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>

#define all(x) x.begin(), x.end()

typedef long long ll;



using namespace std;

signed main()
{
	int money = 210;
	int loses = 0;
	int m, stav;
	string liter;
	for (int q = 0; q < 100; q++)
	{
		if (loses == 3)
			stav = money;
		else
			stav = 1;
		if (q % 2)
			liter = " R";
		else
			liter = " B";
		cout << stav << liter << endl;
		flush(cout);
		cout.flush();
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