#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    if(n==2) {
        cout << "3\n1 2";
        return 0;
    }
    if(n == 1) {
        cout << "1\n1";
        return 0;
    }
    vector<ll> ans = {1, 2, 3};
    for(int i = 3; i < n; i++) {
        ans.push_back(ans.back() * 2);
    }
    cout << ans.back() * 2 << '\n';
    for(auto& x : ans) {
        cout << x << ' ';
    }
    return 0;
}
