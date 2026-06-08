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
    if(h2*60 + m2>=h1*60 + m1){
        ll q = m2;
        for(ll i = h1;i<=h2;i++){
            if(i!=h2){
                m2 = 59;
            }
            else{
                m2 = q;
            }
            for(ll j = m1;j<=m2;j++){
                ll ha = i/10, hb = i%10;
                ll ma = j/10, mb = j%10;
                //cout << ha << " " << hb << " " << ma << " " << mb << endl;
                if(i==j){
                    otvet++;
                }
                else if(i == mb*10+ma || j == hb*10+ha){
                    otvet++;
                }
                else if((ha == hb-1) && (hb == ma-1) && (ma == mb-1)){
                    otvet ++;
                }
            }
            m1 = 0;
        }
    }
    else{
        for(ll i = h1;i<24;i++){
            for(ll j = m1;j<60;j++){
                ll ha = i/10, hb = i%10;
                ll ma = j/10, mb = j%10;
                if(i==j){
                    otvet++;
//                    cout << i << " " << j << endl;
                }
                else if(i == mb*10+ma || j == hb*10+ha){
                    otvet++;
//                     cout << i << " " << j << endl;
                }
                else if((ha == hb-1) && (hb == ma-1) && (ma == mb-1)){
                    otvet ++;
                }
            }
            m1 = 0;
        }
        ll m = m2;
        for(ll i = 0;i<=h2;i++){
            if(i!=h2){
                m2 = 59;
            }
            else{
                m2 = m;
            }
            for(ll j = 0;j<=m2;j++){
                ll ha = i/10, hb = i%10;
                ll ma = j/10, mb = j%10;
                if(i==j){
                    otvet++;
//                     cout << i << " " << j << endl;
                }
                else if(i == mb*10+ma || j == hb*10+ha){
                    otvet++;
//                     cout << i << " " << j << endl;
                }
                else if((ha == hb-1) && (hb == ma-1) && (ma == mb-1)){
                    otvet ++;
                }
            }
        }
    }
    cout << otvet;
    return 0;
}
