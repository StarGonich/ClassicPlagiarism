#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin >> n;

    if (n == 1){
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    if (n == 2){
        cout << -1 << endl;
        return;
    }
    if (n == 3){
        cout << 6 << endl;
        cout << 3 << " " << 2 << " " << 1 << endl;
        return;
    }

    cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--){
        solve();
    }
    return 0;
}
