#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
#endif // _DEBUG
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	char m[] = { 'R', 'B' };
	int start = 210;
	int Lstric = 0;
	int Wstric = 2;
	int lasts = -1;
	int ans;
	while (true)
	{
		if (Lstric != 2) {
			int del;
			if (Wstric == Lstric) {
				del = 5;
			}
			else {
				del = (abs(Wstric - Lstric)) * 2;
			}
			cout << start / (del) << " " << m[Wstric % 2] << endl;
			lasts = start / (del);
		}
		else
		{
			cout << start << " " << m[start % 2] << endl;
			lasts = start;
		}
		cin >> ans;
		if (ans == -1) {
			break;
		}
		if (ans == 0) {
			start -= lasts;
			Wstric--;
			Lstric++;
		}
		if (ans == 1) {
			start += lasts;
			Lstric = -1;
			Wstric++;
		}
		if (start >= 1000) {
			cout << start;
			break;
		}
	}
}