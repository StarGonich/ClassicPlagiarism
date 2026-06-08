#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
using ll =long long;



ll gcd(ll a, ll b){
    if(a>b){
        swap(a, b);
    }
    while(b>1){
        a%=b;
        swap(a, b);
    }
    if(b==1){
        return b;
    }
    return a;
}

ll nok(ll a, ll b){
    return (a*b)/gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll r = n+k;
    ll mn = 1e18;
    ll ans = n+1;
    vector <ll> del;
    for(int i = 2; i <n; i++){
        if(n%i==0){
            if(n*del[i]<=r){
                cout << n*del[i];
                return 0;
            }
            del.push_back(i);
        }
    }
    for(auto c:del){
        if(n+c<=r){
            cout << n+c;
            return 0;
        }
    }
    for(int i = r; i >= n+1; i--){
        if(mn>nok(n, i)){
            ans = i;
            mn = nok(n, i);
        }
    }
    cout << ans;
    return 0;
}
