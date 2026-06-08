#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>


using namespace std;
using ll = long long;
int main()
{
    ll h1, m1, h2, m2, ans = 0;
    cin >> h1 >> m1 >> h2 >> m2;
    ll mh1 = h1*60 + m1, mh2 = h2*60 + m2;
    for (int i = min(mh1, mh2); i <= max(mh1, mh2); i++){
        ll h = i / 60, m = i % 60;
        if (h % 10 == m % 10 && h / 10 == m / 10){
            ans++;
            continue;
        }
        ll r = (m % 10)*10 + (m / 10);
        if (h % 10 == r % 10 && h / 10 == r / 10){
            ans++;
            continue;
        }
        if (h == 1 || h == 12 || h == 23){
            if (m == h + 22){
                ans++;
                continue;
            }
        }
    }
    cout << ans;
    return 0;
}
