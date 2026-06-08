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
    ull otvet = 0;
    ull l = LLONG_MAX;
    for(ull i = n+1;i<=n+k;i++){
        ll q = lcm(i, n);
        if(q < l){
            l = q;
            otvet = i;
        }
    }
    cout << otvet;
}
