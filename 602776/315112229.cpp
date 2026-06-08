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
    vpll seg;
    ll n;
    cin >> n;
    vll perm(n); for (int i = 0; i < n; ++i) cin >> perm[i];
    ll st = 0, len = 1;
    for (int i = 1; i < n; ++i)
    {
        if (perm[i] - perm[i - 1] == 1)
        {
            ++len;
        }
        else
        {
            seg.push_back({ st, len });
            st = i; len = 1;
        }
    }
    seg.push_back({ st, len});
    if (seg.size() == 1)
    {
        cout << "-1 \n";
        return;
    }
    vll arr(seg.size());
    for (int i = 0; i < seg.size(); ++i)
    {
        arr[i] = perm[seg[i].first];
    }
    vll arr_copy = arr;
    sort(arr_copy.begin(), arr_copy.end());
    vll id;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] != arr_copy[i])
            id.push_back(i);
    }
    if (id.size() == 2)
    {
        int id1 = id[0], id2 = id[1];
        cout << seg[id1].first + 1 << " " << seg[id1].second << "\n";
        cout << seg[id2].first + 1 << " " << seg[id2].second << "\n";
    }
    else
    {
        cout << "-1 \n";
        return;
    }
    
   
}
