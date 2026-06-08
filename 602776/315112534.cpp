#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <ios>
#include <iomanip>
#include <cmath>

#define int long long
#define ll long long

using namespace std;

int defineBet(int currSum) {
	int bet = 1;
	while (true) {
		if (bet + bet * 2 + bet * 4 + bet * 8 > currSum) {
		    return bet - 1;
		}
		bet++;
	}
}

int makeBet(int currSum, int bet) {
	cout << bet << " R" << endl;

	int res;
	cin >> res;

	if (res == 0) {
		currSum -= bet;
		return makeBet(currSum, bet * 2);
	}
	else {
		return currSum + bet;
	}
}

void solve() {
	int currSum = 210;
	
	while (currSum < 1000) {
		int bet = defineBet(currSum);

		currSum  = makeBet(currSum, bet);
	}
}

signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}
