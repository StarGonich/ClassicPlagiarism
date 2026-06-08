#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if (a < b){
        swap(a,b);
    }
    while(b > 0){
        a %= b;
        swap(a,b);
    }
    return a;
}

ll lcd(ll a, ll b){
    return a * b / gcd(a,b);
}

void solve(){

    ll k,m,n;
    cin >> k >> n >> m;

    vector<vector<vector<ll>>> t(k + 1, vector<vector<ll>> (n + 1, vector<ll> (m + 1)));
    for (int it = 1; it < k + 1; it++){
        for (int i = 1; i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){
                cin >> t[it][i][j];
            }
        }
    }

    for (int i = k; i >= 1; i++){
        cout << i << " ";
    }
    cout << endl;

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
