#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	long long N, otvet = 0;
	cin >> N;
	for (long long i = 1; i <= N; ++i) {
		int tmp = 0;
		if (i % 5 == 0) {
			++tmp;
		}
		if (i % 6 == 0) {
			++tmp;
		}
		if (i % 4 == 0) {
			++tmp;
		}
		if (tmp == 1) {
			++otvet;
		}

	}
	cout << otvet;

}