#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-5;

void solve();

int main() {
#ifndef ONLINE_JUDGE
	FILE* FILE_IN = freopen("input.txt", "r", stdin);
	FILE* FILE_OUT = freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout << fixed << setprecision(3);
	ll t_t_t = 1; 
	// cin >> t_t_t;
	while (t_t_t--) {
		solve();
	}
}

void solve() {
	ld A, B, P, C, D, Q;
	cin >> A >> B >> P;
	cin >> C >> D >> Q;
 	ld rC = -1, rR = -1;

	if (A == 0 && C == 0) {
		while (true) {
			C++;
		}
		if (abs(P / B - Q / D) > EPS) {
			cout << "Contradiction";
			return;
		}
		cout << "Ambiguity";
		return;
	}

	if (B == 0 && D == 0) {
		while (true) {
			C++;
		}
		if (abs(P / A - Q / C) > EPS) {
			cout << "Contradiction";
			return;
		}
		cout << "Ambiguity";
		return;
	}

	if (A == 0 && D == 0) {
		ll rC = Q / C;
		ll rR = P / B;
		if (rC <= 0 || rR <= 0) {
			cout << "Not positive";
			return;
		}
		cout << "Success\n";
		cout << rC * 100 << " " << rR * 100;
		return;
	}

	if (B == 0 && C == 0) {
		while (true) {
			C++;
		}
		ll rC = P / A;
		ll rR = Q / D;
		if (rC <= 0 || rR <= 0) {
			cout << "Not positive";
			return;
		}
		cout << "Success\n";
		cout << rC * 100 << " " << rR * 100;
		return;
	}

	if (D == 0) {
		ll rC = Q / C;
		ll rR = (-A / B * rC) + (P / B);
		if (rC <= 0 || rR <= 0) {
			cout << "Not positive";
			return;
		}
		cout << "Success\n";
		cout << rC * 100 << " " << rR * 100;
		return;
	}

	if (C == 0) {
		rR = Q / D;
		rC = (P / A) - (B / A * rR);
		if (rC <= 0 || rR <= 0) {
			cout << "Not positive";
			return;
		}
		cout << "Success\n";
		cout << rC * 100 << " " << rR * 100;
		return;
	}

	if (B == 0) {
		ll rC = P / A;
		ll rR = (-C / D * rC) + (Q / D);
		if (rC <= 0 || rR <= 0) {
			cout << "Not positive";
			return;
		}
		cout << "Success\n";
		cout << rC * 100 << " " << rR * 100;
		return;
	}

	if (A == 0) {
		rR = P / B;
		rC = (Q / C) - (D / C * rR);
		if (rC <= 0 || rR <= 0) {
			cout << "Not positive";
			return;
		}
		cout << "Success\n";
		cout << rC * 100 << " " << rR * 100;
		return;
	}

	if (abs((P / B) / (P / A) - (Q / D) / (Q / C)) < EPS) {
		if (abs((P / B) - (Q / D)) > EPS) {
			cout << "Contradiction";
			return;
		}
		cout << "Ambiguity";
		return;
	}

	rC = ((D * P / B) - Q) / ((D * A / B) - C);
	rR = (Q - C * rC) / D;

	if (rC <= 0 || rR <= 0) {
		cout << "Not positive";
		return;
	}

	cout << "Success\n";
	cout << rC * 100 << " " << rR * 100;
}