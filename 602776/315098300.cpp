#include <iostream>
#include <string> 
#include <vector> 
#include <algorithm> 
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <cstdlib>
using namespace std;



int main() {
	int n, r = 0;
	cin >> n;
	for (int i = 0; i < n + 1; i += 4) {
		if (!(i % 4) && i % 5 && i % 6 && i) {
			r++;
		}
	}
	for (int i = 0; i < n + 1; i += 5) {
		if (!(i % 5) && i % 4 && i % 6 && i) {
			r++;
		}
	}
	for (int i = 0; i < n + 1; i += 6) {
		if (!(i % 6) && i % 5 && i % 4 && i) {
			r++;
		}
	}
	cout << r;

	return 0;
}