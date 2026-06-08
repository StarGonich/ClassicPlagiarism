#include <iostream>
#include<cmath>
#include <vector>
using namespace std;
void BigBoom(vector<pair<pair<int, int>, bool>>& mins,int number) {
	mins[number].second = false;
	for (int i = 0; i < mins.size(); ++i) {
		if (mins[i].first.first >= (mins[number].first.first - mins[number].first.second) && mins[i].first.first <= (mins[number].first.first + mins[number].first.second)&&mins[i].second==true) {
		 BigBoom(mins, i);
		}
	}
}
int main()
{
	int n,number;
	cin >> n;
	vector<pair<pair<int,int>,bool>> coordinats(n);
	for (int i = 0; i < n; ++i) {
		cin >> coordinats[i].first.first;
		coordinats[i].second = true;
	}
	for (int i = 0; i < n; ++i) {
		cin >> coordinats[i].first.second;
	}
	cin >> number;
	BigBoom(coordinats, number - 1);
	int otvet =0;
	for (int i = 0; i < coordinats.size(); ++i) {
		if (!coordinats[i].second) {
			++otvet;
		}
	}
	cout << otvet;
}