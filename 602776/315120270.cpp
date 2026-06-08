#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
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