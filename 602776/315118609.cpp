
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
    ll s = 210;
    vector<ll> last;
    ll n = 20;
    char c = 'R';
    while (s < 1000)
    {

        cout << n << ' ' << c << endl;

        ll x;
        cin >> x;

        if (x == 0)
        {
            s -= n;
        }
        else
        {
            s += n;
        }

        if(x == -1)
            return 0;

        last.emplace_back(x);

        if (last.size() > 2 && last[last.size() - 1] == 0 && last[last.size() - 2] == 0 && last[last.size() - 3] == 0)
            n = s;
        else if (last.size() > 2 && last[last.size() - 1] == 0 && last[last.size() - 2] == 0)
            n = 30;
        else if (last.size() > 1 && last[last.size() - 1] == 0)
            n = 20;
        else n = 10;
    }
}

