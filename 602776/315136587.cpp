#include <iostream>
#include <string>

using namespace std;

int main()
{
	int money = 210, cycle{}, st = 5;
	cout << st << " B" << endl;

	int x;
	cin >> x;
	while (x != -1 && money < 1000) {
		
		if (x == 0) {
			++cycle;
			money -= st;

			if (cycle == 1)
				st = 23;
			else if (cycle == 2)
				st = 48;
			else if (cycle == 3) {
				cycle = 0;
				st = money;
				money = 0;
			}
		}
		else if (x == 1) {
			money += st * 2;
			cycle = 0;
			st = 10;
		}

		if (money >= 1000)
			break;

		cout << st << " B" << endl;
		cin >> x;
	}

}

