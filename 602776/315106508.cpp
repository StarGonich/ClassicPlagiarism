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
		cout << "Ambiguity";
		return;
	}
	if (B == 0 && D == 0) {
		cout << "Ambiguity";
		return;
	}

	if (D == 0) {
		rC = Q / C;
		rR = (P - A * rC) / B;

		if (abs(A * rC + B * rR - P) < EPS ||
			abs(C * rC + D * rR - Q) < EPS) {
			cout << "Contradiction";
			return;
		}

		if (rC <= 0 || rR <= 0) {
			cout << "Not positive";
			return;
		}
	}

	if (C == 0) {
		rR = Q / D;
		rC = (P - B * rR) / A;

		if (abs(A * rC + B * rR - P) < EPS ||
			abs(C * rC + D * rR - Q) < EPS) {
			cout << "Contradiction";
			return;
		}

		if (rC <= 0 || rR <= 0) {
			cout << "Not positive";
			return;
		}
	}

	if (B == 0) {
		rC = P / A;
		rR = (Q - C * rC) / D;

		if (abs(A * rC + B * rR - P) < EPS ||
			abs(C * rC + D * rR - Q) < EPS) {
			cout << "Contradiction";
			return;
		}

		if (rC <= 0 || rR <= 0) {
			cout << "Not positive";
			return;
		}
	}

	if (A == 0) {
		rR = P / B;
		rC = (Q - D * rR) / C;

		if (abs(A * rC + B * rR - P) < EPS ||
			abs(C * rC + D * rR - Q) < EPS) {
			cout << "Contradiction";
			return;
		}

		if (rC <= 0 || rR <= 0) {
			cout << "Not positive";
			return;
		}
	}

	if (A != 0 && B != 0 && C != 0 && D != 0) {
		if (abs(C * B / A - D) < EPS && abs(C * P / A - Q) > EPS || 
			abs(C * B / A - D) > EPS && abs(C * P / A - Q) < EPS) {
			cout << "Contradiction";
			return;
		}

		if (abs((D * A / B) - C) < EPS) {
			cout << "Ambiguity";
			return;
		}

		rC = ((D * P / B) - Q) / ((D * A / B) - C);
		rR = (Q - C * rC) / D;

		if (abs(A * rC + B * rR - P) > EPS ||
			abs(C * rC + D * rR - Q) > EPS) {
			cout << "Contradiction";
			return;
		}

		if (rC <= 0 || rR <= 0) {
			cout << "Not positive";
			return;
		}
	}

	cout << "Success\n";
	cout << rC * 100 << " " << rR * 100;
}