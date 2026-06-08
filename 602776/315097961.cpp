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

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	cout << (n / 4) + (n / 5) + (n / 6) - 2 * (n / 12) - 2 * (n / 20) - 2 * (n / 30) + 3 * (n / 60);
}