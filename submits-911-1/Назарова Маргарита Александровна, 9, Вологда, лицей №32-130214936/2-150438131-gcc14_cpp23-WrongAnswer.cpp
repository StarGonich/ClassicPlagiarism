#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using ll =long long;

bool isPrime(int x){
    
}

int main()
{
    ll n;
    cin >> n;
    if(n==1){
        cout << 1 << "\n" << 1;
        return 0;
    }
    if(n==2){
        cout << -1;
        return 0;
    }
    
    ll ans = 1;
    for(ll i = 2; i <= n; i++){
        ans+=i;
    }
    cout << ans << "\n";
    for(ll i = 1; i <= n; i++){
        cout << i << " ";
    }
    return 0;
}
