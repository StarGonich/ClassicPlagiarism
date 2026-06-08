#include <iostream>
#include<cmath>
#include <vector>
using namespace std;
void BigBoom(vector<pair<pair<long long, long long>, bool>>& mins,long long number) {
	mins[number].second = false;
	for (long long i = 0; i < mins.size(); ++i) {
		if ((mins[i].first.first >= (mins[number].first.first - mins[number].first.second)) &&( mins[i].first.first <= (mins[number].first.first + mins[number].first.second))&&(mins[i].second==true)) {
			cout << "\\|/" << i << endl;
			BigBoom(mins, i);
		}
	}
}
int main()
{
	long long n,number;
	cin >> n;
	vector<pair<pair<long long,long long>,bool>> coordinats(n);
	for (long long i = 0; i < n; ++i) {
		cin >> coordinats[i].first.first;
		coordinats[i].second = true;
	}
	for (long long i = 0; i < n; ++i) {
		cin >> coordinats[i].first.second;
	}
	cin >> number;
	BigBoom(coordinats, number - 1);
	long long otvet =0;
	for (long long i = 0; i < coordinats.size(); ++i) {
		if (!coordinats[i].second) {
			++otvet;
		}
	}
	cout << otvet;
}