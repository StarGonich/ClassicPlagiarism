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
#define endl '\n'
typedef long long ll;



using namespace std;
signed main()
{
	cin.sync_with_stdio(0); cout.sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	cnt += n / 4;
	cnt += n / 6;
	cnt += n / 5;
	cnt -= n / 12;
	cnt -= n / 20;
	cnt += (n / 60);

	cnt -= n / 20;
	cnt -= n / 30;
	cnt += (n / 60);

	cnt -= n / 12;
	cnt -= n / 30;
	cnt += (n / 60);
	cout << cnt << endl;
	
}