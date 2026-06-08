#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int ch465 = n / 12 / 5;
	int ch45 = n / 20;
	int ch46 = n / 12;
	int ch4 = n / 4;
	int ch56 = n / 30;
	int ch5 = n / 5;
	int ch6 = n / 6;

	int answ = 0;
	if (ch465){
		ch4 -= ch465;
		ch5 -= ch465;
		ch6 -= ch465;
		ch46 -= ch465;
		ch45 -= ch465;
		ch56 -= ch465;
	}
	if (ch46) {
		ch4 -= ch46;
		ch6 -= ch46;
	}
	if (ch45) {
		ch4 -= ch45;
		ch5 -= ch45;
	}
	if (ch56) {
		ch5 -= ch56;
		ch6 -= ch56;
	}
	answ += ch4 + ch5 + ch6;
	cout << answ;
}