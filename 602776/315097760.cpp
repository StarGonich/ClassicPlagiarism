
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main()
{
    ll n;
    cin >> n;
    ll ans = n / 4 + n / 5 + n / 6 - n / 12 * 2 - n / 20 * 2 - n / 30 * 2 + n / 60;
    cout << ans;
}

