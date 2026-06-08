#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using ll =long long;

int main()
{
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2>> m2;
    ll ans = 0;
    while(h1!=h2 || m1!=m2){
        if(h1==m1){
            ans++;
        }
        if(h1/10==m1%10 && h1%10==m1/10){
            ans++;
        }
        if(h1/10+1==h1%10 && h1%10+1==m1/10 && m1/10+1==m1%10){
            ans++;
        }
        m1++;
        if(m1==60){
            m1=0;
            h1++;
            if(h1==24){
                h1=0;
            }
        }
    }
    if(h1==m1){
            ans++;
        }
        if(h1/10==m1%10 && h1%10==m1/10){
            ans++;
        }
        if(h1/10+1==h1%10 && h1%10+1==m1/10 && m1/10+1==m1%10){
            ans++;
        }
    cout << ans;
    return 0;
}
