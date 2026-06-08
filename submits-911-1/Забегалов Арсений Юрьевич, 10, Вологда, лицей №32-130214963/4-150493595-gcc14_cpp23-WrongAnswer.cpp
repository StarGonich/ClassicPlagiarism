#include <algorithm>
#include <iostream>
#include <climits>
#include <utility>
#include <cstdio>
#include <vector>
#include <set>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string;

#define matrix vector<vector<ll>>
#define f first
#define s second

ull lcm(ull a, ull b){
    ull x = a, y = b;
    while(x!=0&&y!=0){
        x>y?x%=y:y%=x;
    }
    return (a/(x+y))*b;
}

int main()
{
    ull n, k;cin >> n>>k;
    if(k>=n){
        cout << n*2LL;
        return 0;
    }
    vector<ll> d;
    for(ll i = 1;i*i<=n;i++){
        if(n%i==0){
            d.push_back(i);
            d.push_back(n/i);
        }
    }
    ll otvet = 0;
    ll l = LLONG_MAX;
    for(auto x : d){
        if(x<k){
            ll q = lcm(n, x+n);
            if(q < l){
                l = q;
                otvet = n+x;
            }
        }
    }
    cout << otvet;
}
