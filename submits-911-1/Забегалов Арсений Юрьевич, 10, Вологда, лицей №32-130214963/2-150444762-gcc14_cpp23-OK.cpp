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
    ll n;cin >> n;
    if(n==1){
        cout << 2 << endl << 2;
        return 0;
    }
    if(n==2){
        cout << -1;
        return 0;
    }
    ll d = (n-3)+1;
    d = (3<<d);
    cout << d << endl;
    cout << 1 << " " << 2 << " " << 3 << " ";
    n-=3;
    ll num = 6;
    while(n>0){
        cout << num << " ";
        num*=2;
        n--;
    }
    return 0;
}
