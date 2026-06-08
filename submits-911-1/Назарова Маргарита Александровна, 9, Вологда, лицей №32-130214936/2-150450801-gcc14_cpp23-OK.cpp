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
    ll ans = 6;
    int k = n-3;
    for(int i = 0; i < k; i++){
        ans*=2;
    }
    cout << ans << "\n" << 1 << " " << 2 << " " << 3 << " ";
    ll f = 6;
    for(int i = 4; i <= n; i++){
        cout << f << " ";
        f*=2;
    }
    return 0;
}
