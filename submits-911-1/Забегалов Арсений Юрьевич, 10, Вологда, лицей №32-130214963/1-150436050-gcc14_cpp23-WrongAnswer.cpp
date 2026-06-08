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
using str = string;

#define matrix vector<vector<ll>>

int main()
{
    ll h1, h2, m1, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    ll otvet = 0;
    for(ll i = h1;i<=h2;i++){
        for(ll j = m1;j<=m2;j++){
            ll ha = i/10, hb = i%10;
            ll ma = j/10, mb = j%10;
            if(i==j){
                otvet++;
            }
            else if(i == mb*10+ma || j == hb*10+ha){
                otvet++;
            }
            else if(ha == hb+1 && hb == ma+1 && ma == mb+1){
                otvet ++;
            }
        }
    }
    cout << otvet;
    return 0;
}
