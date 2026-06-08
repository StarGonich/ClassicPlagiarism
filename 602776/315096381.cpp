
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

int main()
{
	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 4 == 0 && i % 5 != 0 && i % 6 != 0) {
			res++;
			continue;
		}
		if (i % 4 != 0 && i % 5 == 0 && i % 6 != 0) {
			res++;
			continue;
		}
		if (i % 4 != 0 && i % 5 != 0 && i % 6 == 0) {
			res++;
			continue;
		}
	}
	cout << res;
}
