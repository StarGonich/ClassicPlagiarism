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


int main(){
    ll k;cin >> k;
    if(k==2){
        ll n, m;
        cin >> n >> m;
        matrix q(n, vector<ll>(m));
        matrix w(n, vector<ll>(m));
        ll sum = 0;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                cin >> q[i][j];
                sum+=q[i][j];
            }
        }
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                cin >> w[i][j];
            }
        }
        if(sum == 0){
            cout << 2 << " " << 1;
        }
        else{
            cout << 1 << " " << 2;
        }
    }
    else{
        for(ll i = 0;i<k;i++){
            cout << k-i << " ";
        }
    }
}
