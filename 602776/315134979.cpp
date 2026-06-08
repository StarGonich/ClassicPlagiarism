#include <iostream>
#include <string>

#include <iterator>
#include <numeric>
#include <algorithm>
#include <cmath>

#include <unordered_set>
#include <unordered_map>

#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS

 


using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//reopen("input.txt", "r", stdin);

	int money = 210, cycle{}, st = 5;
	cout << st << " R" << endl;

	int x;
	cin >> x;
	while (x != -1 && money < 1000) {
		
		
		if (x == 0) {
			++cycle;
			money -= st;

			if (cycle == 1)
				st = 14;
			else if (cycle == 2)
				st = 25;
			else if (cycle == 3) {
				cycle = 0;
				st = money;
				money = 0;
			}
		}
		else if (x == 1) {
			money += st * 2;
			cycle = 0;
			st = 5;
		}

		if (money >= 1000)
			break;

		cout << st << " R" << endl;
		cin >> x;
	}




}

