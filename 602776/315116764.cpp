#include <iostream>
#include<cmath>
#include <vector>
using namespace std;
void BigBoom(vector<pair<pair<long long, long long>, bool>>& mins,long long number) {
	mins[number].second = false;
	for (long long i = 0; i < mins.size(); ++i) {
		if ((mins[i].first.first >= (mins[number].first.first - mins[number].first.second)) &&( mins[i].first.first <= (mins[number].first.first + mins[number].first.second))) {
			if (mins[i].second == true) {
				BigBoom(mins, i);
			}
		}
	}
}
int main()
{
	int money = 210,stavka=1,proigrish=0,result;
	char color = 'B';
	while (money < 1000 && money>0) {
		if (proigrish == 3) {
			stavka = money;
			color = 'B';
		}
		else {
			stavka = 10;
			color = 'R';
		}
		cout << stavka << " " << color << endl;
		cin >> result;
		if (result == 0) {
			++proigrish;
		}
		else if (result == -1) {
			return 0;
		}
		else if (result == 1) {
			proigrish = 0;
		}
	
	}
}