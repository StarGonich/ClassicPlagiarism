#include <iostream>
#include<cmath>
#include <vector>
using namespace std;
void BigBoom(vector<pair<pair<long long, long long>, bool>>& mins,long long number,long long& kolvo) {
	mins[number].second = false;
	for (long long i = 0; i < mins.size(); ++i) {
		if ((mins[i].first.first >= (mins[number].first.first - mins[number].first.second)) &&( mins[i].first.first <= (mins[number].first.first + mins[number].first.second))) {
			if (mins[i].second == true&&kolvo!=mins.size()-1) {
				++kolvo;
				BigBoom(mins, i,kolvo);
			}
			else if (mins[i].second == true && kolvo == mins.size() - 1) {
				mins[i].second = false;
				break;
			}
		}
	}
}
int main()
{
	long long n, number;
	cin >> n;
	vector<pair<pair<long long, long long>, bool>> coordinats(n);
	for (long long i = 0; i < n; ++i) {
		cin >> coordinats[i].first.first;
		coordinats[i].second = true;
	}
	for (long long i = 0; i < n; ++i) {
		cin >> coordinats[i].first.second;
	}
	cin >> number;
	long long kolvo = 0;
	BigBoom(coordinats, number - 1,kolvo);
	long long otvet = 0;
	for (long long i = 0; i < coordinats.size(); ++i) {
		if (!coordinats[i].second) {
			++otvet;
		}
	}
	cout << otvet;
}