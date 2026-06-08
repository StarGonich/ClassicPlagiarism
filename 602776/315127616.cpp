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
	int stric = 0;
	int lasts = -1;
	int ans;
	while (true)
	{
		if (stric != 3) {
			cout << start / 8 << " " << m[stric % 2] << endl;
			lasts = start / 8;
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
			stric++;
		}
		if (ans == 1) {
			start += lasts;
			stric = 0;
		}
		if (start >= 1000) {
			break;
		}
	}
}