#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int mainA() {
	double A, B, P;
	cin >> A >> B >> P;
	/*A /= 100;
	B /= 100;*/
	double C, D, Q;
	cin >> C >> D >> Q;
	/*C /= 100;
	D /= 100;*/

	double x = (D * P - B * Q)
		/ (A * D - C * B);
	double y = (Q - x * C) / D;

	if ((D * P - B * Q) == 0) {
		cout << "Ambiguity\n";
		return 0;
	}
	if ((A * D - C * B) == 0) {
		cout << "Contradiction\n";
		return 0;
	}
	if (x < 0 || y < 0)
	{
		cout << "Not positive\n";
		return 0;
	}
	cout << "Success\n";
	cout << x*100 << " " << y * 100;

}

pair<int, string> rec(bool maxim, string const & s) {
	int k = 0;
	pair<int, string> ret = { 0,"" };
	int l = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			if (k == 0)
				l = i;
			k++;
		}
		else if (s[i] == ')') {
			k--;
			if (k == 0) {
				if (l != 0 && s[l - 1] == '-') {
					pair<int, string> a;
					a = rec(!maxim, s.substr(l + 1, i - l-1));
					a.second = "-(" + a.second + ')';
					a.first *= -1;
					pair<int, string> b = rec(maxim, s[l - 1] + s.substr(l + 1, i - l-1));
					if (maxim) {
						if (a.first > b.first) {
							ret.first += a.first;
							ret.second += a.second;
						}
						else {
							ret.first += b.first;
							ret.second += b.second;
						}
					}
					else {
						if (a.first > b.first) {
							ret.first += b.first;
							ret.second += b.second;
						}
						else {
							ret.first += a.first;
							ret.second += a.second;
						}
					}
				}
				else {
					pair<int, string> a;
					if (l == 0) {
						a = rec(maxim, s.substr(l + 1, i - l-1));
						a.second = '(' + a.second + ')';
					}
					else {
						a = rec(maxim, s.substr(l + 1, i - l - 1));
						a.second = "+(" + a.second + ')';
					}
					ret.first += a.first;
					ret.second += a.second;
				}
			}
		}
		else if (k == 0 && s[i] != '-' && s[i] != '+') {
			if (i == 0 || s[i-1] == '+')
				ret.first += s[i] - '0';
			else
				ret.first -= s[i] - '0';
			if (i != 0)
				ret.second += s[i-1];
			ret.second += s[i];
		}
	}
	return ret;
}

int main() {
	string s; cin >> s;
	pair<int, string> ans = rec(true, s);
	cout << ans.first << "\n" << ans.second;
}

/*

a-b
a+b

*/

/*

250/200 = 1.25
150/200 = 0.75
49/46 = 49/46


*/

/*

1 2 3 4
n-1: 1 2; 2 3; 3 4;
n-2: 1 2 4; 1 3 4;

1 2 3 4 5 6 7
n-1
1 2 4; 1 2 5; 1 2 6; 1 2 7; - n-3
2 3 5; 2 3 6; 2 3 7; - n-4
3 4 1; 3 4 6; 3 4 7; - n-4
4 5 1; 4 5 2; 4 5 7; - n-4
5 6 1; 5 6 2; 5 6 3; - n-4
6 7 1; 6 7 2; 6 7 3; 6 7 4; - n-3
1 2 4 6; 1 2 4 7; 1 2 5 7; - n-4
2 3 5 7; - n-6
3 4 1 6; 3 4 1 7; - n-5
4 5 1 7; 4 5 2 7; - n-5
5 6 1 3; - n-6
6 7 1 3; 6 7 1 4; 6 7 2 4; - n-4

1 2: b = n-3
	2: 1
	3: n-3
	4: n-4
2 3: b = n-4
	2: 1
	3: n-4
	4: n-6
3 4: a = 3-2, b = n-5
	2: 1
	3: n-4
	4: n-5
*/