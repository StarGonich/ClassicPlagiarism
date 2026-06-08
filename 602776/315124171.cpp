
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <deque>
#include <algorithm>
#include <math.h>

using namespace std;


typedef long long ll;
typedef long double ld;

int main2()
{
	int n;
	cin >> n;
	int res = 0;
	//*
	for (int i = 1000000; i <= n; i++) {
		if (i % 4 == 0 && i % 5 != 0 && i % 6 != 0) {
			//cout << i << " ";
			res++;
			continue;
		}
		if (i % 4 != 0 && i % 5 == 0 && i % 6 != 0) {
			//cout << i << " ";
			res++;
			continue;
		}
		if (i % 4 != 0 && i % 5 != 0 && i % 6 == 0) {
			//cout << i << " ";
			res++;
			continue;
		}
	}
	//*/
	
	

	///*


	res = 0;
	res += (n - n % 4) / 4;
	res += (n - n % 5) / 5;
	res += (n - n % 6) / 6;
	//*/
	/*
	int f4 = 4;
	int f5 = 5;
	int f6 = 6;
	for (int i = 1; f4 * f5 * i <= n; i++) {
		res--;
	}
	for (int i = 1; f5 * f6 * i <= n; i++) {
		res--;
	}
	for (int i = 1; f4 * f6 * i <= n; i++) {
		res--;
	}
	*/

	/*
	for (int i = 1; i <= n; i++) {
		cout << "";
	}
	*/
	cout << endl;
	cout << res;
	return 0;
}


struct Mina
{
	int pos;
	int d;
	int state;
};

/*
* 0 - unactive
* 1 - risky
* 2 - destroed
*/

int main4() {
	int n;
	cin >> n;

	Mina a = Mina();
	a.state = 0;

	vector<vector<Mina>> matrix(n, vector<Mina>(n, a));

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		int d;
		cin >> d;
		Mina curr = Mina();
		curr.pos = x;
		curr.d = d;
		curr.state = 0;


	}

	int pos;
	cin >> pos;









	return 0;
}

int main() {

	ll n;
	cin >> n;


	ll n1 = n -(n % 4);
	ll r1 = ((4 + n1) / 4 - 1);
		r1++;
	if (n % 4 == 0) {
	}
	ll res1 = r1 * 0.8 * 2 / 3;
	/*
	if (n % 4 != 0) {
		res1++;
	}
	*/

	ll n2 = n -(n % 5);
	ll r2 = ((5 + n2) / 5 - 1);
		r2+=1;
	if (n % 5 == 0) {
	}
	ll res2 = r2 * 0.75 * 2 / 3;
	/*
	if (n % 5!= 0) {
		res2++;
	}
	*/

	ll n3 = n -(n % 6);
	
	ll r3 = ((6 + n3) / 6 - 1);
		r3+=1;
	if (n % 6 == 0) {
	}
	ll res3 = r3 * 0.75 * 0.8;
	/*
	if (n % 6 != 0) {
		res3++;
	}
	*/

	int res = 0;
	int res4 = 0;
	int res5 = 0;
	
	/*
	if (n % 4 == 0 && n % 5 == 0) {
		res1--;
	}

	if (n % 6 == 0 && n % 5 == 0) {
		res1--;
	}

	if (n % 4 == 0 && n % 6 == 0) {
		res1--;
	}
	*/


	ll ares = floor(n / 60) * 20;
	ll aboba = n % 60;
	res = 0;
	for (int i = n - aboba; i <= n; i++) {
		if (i % 4 == 0 && i % 5 != 0 && i % 6 != 0) {
			//cout << i << " ";
			res++;
			continue;
		}
		if (i % 4 != 0 && i % 5 == 0 && i % 6 != 0) {
			//cout << i << " ";
			res++;
			continue;
		}
		if (i % 4 != 0 && i % 5 != 0 && i % 6 == 0) {
			//cout << i << " ";
			res++;
			continue;
		}
	}



	//cout << res1 << " " << res2 << " " << res3 << endl;
	//cout << res4 << endl;
	//cout << res1 + res2 + res3;
	//cout << endl << res + ares << endl;
	//cout << (res1 + res2 + res3) - res;
	cout << res + ares;
	return 0;
}