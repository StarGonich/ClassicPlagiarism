#include <iostream>
#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define PI acos(-1)
//#define _DEBUG
#pragma GCC optimize ("03,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;


void solve(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i <= n; i++){
        if (i % 6 != 0 && i % 4 != 0 && i % 5 == 0 || i % 6 == 0 && i % 4 != 0 && i % 5 != 0 || i % 6 != 0 && i % 4 == 0 && i % 5 != 0)
            ans++;
    }
    cout << ans << endl;
}
int main(){
    #if defined _DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdin)

    #endif
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    
}