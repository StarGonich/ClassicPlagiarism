//#include <udacha$$$>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
using pll = pair <ll, ll>;
using vll = vector <ll>;
using vpll = vector <pll>;
using vvll = vector <vll>;

void solve();


int main()
{
    int t = 1; //cin >> t;
    while (t--)
        solve();
}

void solve()
{
    ll sum = 210;
    vector <char> colour{ 'B', 'B', 'B', 'B', 'B', 'R', 'R', 'R', 'R', 'R' };
    ll use = 0, mod = 10, cnt = 0, res;
    while (sum < 1000 && sum > 0)
    {
        if (cnt == 3)
        {
            cout << sum << " " << colour[use] << endl;
            cin >> res;
            if (res == 1)
            {
                sum *= 2;
            }
            else if (res == 0)
            {
                sum = 0;
            }
            else
            {
                return;
            }
            cnt = 0;

        }
        else
        {
            cout << 8 << " " << colour[use] << endl;
            cin >> res;
            if (res == 1)
            {
                cnt = 0;
                sum += 8;
            }
            else if (res == 0)
            {
                ++cnt;
                sum -= 8;
            }
            else
            {
                return;
            }
        }
        ++use;
        use %= mod;
    }


}
