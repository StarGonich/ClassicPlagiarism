#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
#include <cmath>
#include <bitset>
#include <list>
#include <math.h>
#include <iomanip>
#include <fstream>

# define M_PI           3.14159265358979323846 

using namespace std;

int mod = 1e9 + 7;

bool comp(long double a, long double b)
{
	if (abs(a - b) < 0.000000001) return 1;
	else return 0;
}

int main()//случай: была ли отсорт + повт эл???
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, res, bank = 210;
	while (bank < 1000)
	{
		k = bank / 15;
		cout << k << " R" << endl;
		cin >> res;
		if (res) { bank += k; continue; }
		cout << 2 * k << " R" << endl;
		cin >> res;
		if (res) { bank += 2 * k; continue; }
		cout << 3 * k << " R" << endl;
		cin >> res;
		if (res) { bank += 6 * k; continue; }
		cout << bank - 7 * k << " R" << endl;
		cin >> res;
		if (res) { bank = (bank - 7 * k) * 2; continue; }
	}
	return 0;
}
