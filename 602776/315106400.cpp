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
	double a, b, p, c, d, q;
	cin >> a >> b >> p >> c >> d >> q;
	if (int(a) == 0 || int(b) == 0 || int(c) == 0 || int(d) == 0)
	{ 
		if (int(a) == 0 && int(c) == 0)
		{
			cout << "Ambiguity";
			return 0;
		}
		if (int(b) == 0 && int(d) == 0)
		{
			cout << "Ambiguity";
			return 0;
		}
	}
	else {
		if (int(a) % int(c) == 0 && int(b) % int(d) == 0 && int(p) % int(q) == 0)
		{
			cout << "Ambiguity";
			return 0;
		}
		if (int(c) % int(a) == 0 && int(d) % int(b) == 0 && int(q) % int(p) == 0)
		{
			cout << "Ambiguity";
			return 0;
		}
		if (int(a) % int(c) == 0 && int(b) % int(d) == 0)
		{
			cout << "Contradiction";
			return 0;
		}
		if (int(c) % int(a) == 0 && int(d) % int(b) == 0)
		{
			cout << "Contradiction";
			return 0;
		}
	}
	double x, y;
	x = (p * d - b * q) / (a * d - c * b);
	y = (q * (a * d - c * b) - c * p * d + c * b * q) / (a * d * d - c * d * b);
	if (x < 0 || y < 0)
	{
		cout << "Not positive";
		return 0;
	}
	cout << "Success" << endl;
	printf("%f ", x * 100);
	printf("%f", y * 100);
}