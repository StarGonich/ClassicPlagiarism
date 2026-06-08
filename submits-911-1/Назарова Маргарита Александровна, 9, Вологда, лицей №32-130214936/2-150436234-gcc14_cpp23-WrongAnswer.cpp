#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using ll =long long;

int main()
{
    ll n;
    cin >> n;
    ll ans = 1;
    for(ll i = 2; i <= n; i++){
        ans*=i;
    }
    cout << ans << "\n";
    for(ll i = 1; i <= n; i++){
        cout << i << " ";
    }
    return 0;
}
