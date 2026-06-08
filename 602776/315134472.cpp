
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stack>
#include <deque>
#include <algorithm>
#include <math.h>

using namespace std;


typedef long long ll;
typedef long double ld;


bool check(vector<bool>& tries) {
	for (int i = 0; i < tries.size(); i++) {
		if (tries[i] == 1) {
			return 0;
		}
	}
	return 1;
}

int main() {

	ll balance = 210;

	vector<bool> tries(3, 0);

	ll stavka = balance / 16;
	string r = " R";
	string b = " B";
	
	int res = 0;
	for (int i = 0; i < 100; i++) {
		if (i == 0) {
			cout << stavka << r;
			cout << endl;

			cin >> res;

			if (res == 0) {
				tries[0] = 0;
				balance -= 2;
				stavka *= 2;
			} 
			if (res == 1) {
				tries[0] = 1;
				balance += stavka;
				stavka *= 2;
			}
			//cout << "Curr balance: " << balance << endl;
			cout.flush();
			continue;
		} 
		if (i == 1) {
			cout << stavka << r;
			cout << endl;
			cin >> res;

			if (res == 0) {
				tries[1] = 0;
				balance -= stavka;
				stavka *= 2;
			}
			if (res == 1) {
				tries[1] = 1;
				balance += 2;
				stavka *= 2;
			}

			//cout << "Curr balance: " << balance << endl;
			cout.flush();
			continue;
		}
		if (i == 2) {
			cout << stavka << r;
			cout << endl;
			cin >> res;

			if (res == 0) {
				tries[2] = 0;
				balance -= stavka;
				stavka *= 2;
			}
			if (res == 1) {
				tries[2] = 1;
				balance += 2;
				stavka *= 2;
			}

			//cout << "Curr balance: " << balance << endl;
			cout.flush();
			continue;
		}

		if (check(tries)) {
			cout << balance << r;
			cout << endl;
			int res = 1;
			cin >> res;
			tries[i % 3] = 1;
			balance *= 2;
			stavka = balance / 16;
			//cout << "Curr balance: " << balance << endl;
			continue;
		}

		cout << stavka << r;
		cout << endl;
		
		int res = 0;
		cin >> res;

		if (res == 0) {
			balance -= stavka;
			tries[i % 3] = 0;
			stavka *= 2;

			//cout << "Curr balance: " << balance << endl;
		}

		if (res == 1) {
			balance += stavka;
			tries[i % 3] = 1;
			stavka = balance / 16;
			//cout << "Curr balance: " << balance << endl;
		}

		if (balance >= 1000) {
			//cout << "Final balance: " << balance;
			return 0;
		}
		//cout << "CURR B: " << balance << endl;
		cout.flush();
	}


	return 0;
}
