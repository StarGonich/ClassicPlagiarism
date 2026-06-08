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
    ll n, k;
    cin >> n >> k;
    ll r = n+k;
    ll mn = 1e18;
    ll ans = n+1;
    for(int i = r; i >= n+1; i--){
        if(mn>nok(n, i)){
            ans = i;
            mn = nok(n, i);
        }
    }
    cout << ans;
    return 0;
}
