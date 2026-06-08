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
    ll base_stake = 10, cnt = 0, cur_stake = base_stake, res;
    vector <char> cur_color{ 'R', 'B' };
    for (int i = 0; sum < 1000; ++i)
    {
        if (cnt == 0)
        {
            cur_stake = base_stake;
        }
        else if (cnt == 1)
        {
            cur_stake = base_stake * 2;
        }
        else if (cnt == 2)
        {
            cur_stake = base_stake * 4;
        }
        else
        {
            cur_stake = 11 * base_stake;
        }
        cout << cur_stake << " " << cur_color[i & 1] << endl;
        cin >> res;
        if (res == 1)
        {
            sum += cur_stake;
            cnt = 0;
        }
        else if (res == 0)
        {
            sum -= cur_stake;
            ++cnt;
        }
        else
        {
            return;
        }


    }


}
